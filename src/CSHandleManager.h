#pragma once
#include	<cassert>
#include<vector>

//#include "CSHandle.h"
namespace cs
{
	/**
	*1-p60
	*1.Data类型不是一般意义上的C++类，不应该具有完成任何重要操作的构造函数和
	*  析构函数，如分配资源，释放资源
	*2.所以类内部使用的是Data,而不是指针
	*  指针再重新加载时信息已经丢失，所以可以放对象在vector可以记录状态信息
	*3.这个类不应该被客户程序使用，应该对其封装在使用，如组合类
	*4.对象被释放时index被放在了空闲列表中，Data对象不是析构，这样可以被重复利用，并且保证
	*  句柄不会重复，相应的data只需要被初始化即可
	*/
	template<typename Data,typename CSHandle>
	class CSHandleManager
	{
	private:
		typedef std::vector<unsigned int> MagicVec;
		typedef std::vector<unsigned int> FreeVec;
		//Data* or Data ?
		typedef std::vector<Data> UserVec;

		UserVec userData_;
		MagicVec magicNumbers_;
		FreeVec freeSlots_;
	public:
		CSHandleManager(void) {};
		~CSHandleManager(void) {};

		//accquire an useable handle
		Data* Acquire(CSHandle& handle);
		void Release(CSHandle handle);

		//defererence
		Data* Dereference(CSHandle handle);
		//const....const
		const Data* Dereference(CSHandle handle)const;

		//query
		unsigned int GetUsedHandleCount(void)
		{
			return userData_.size()
		}
		bool HasUsedHandles(void) const
		{
			//return(!!GetUsedHandleCount())????
			return(!GetUsedHandleCount())
		}

	};

	template<typename Data, typename CSHandle>
	Data* CSHandleManager<Data, CSHandle>::Acquire(CSHandle& handle)
	{
		unsigned int index;
		//列表为空
		if (freeSlots_.empty())
		{
			index = magicNumbers_.size();
			handle.Init(index);
			//???Data*  ?
			userData_.push_back(Data());
			magicNumbers_.push_back(handle.GetMagic());
		}
		else
		{
			//从空闲列表中取得index,index一定不重复，
			//如果为空，说明0-magicNumbers-1已经被使用了
			index = freeSlots_.back();
			handle.init(index);
			userData_.pop_back();
			magicNumbers_[index] = hangle.GetMagic();
		}

		return (userData_.begin()+index)
	}

	template<typename Data, typename CSHandle>
	void CSHandleMerger<Data, CSHandle> ::Realse(CSHandle handle)
	{
		unsigned int index = handle.GetIndex();
		assert(index < userData_.size());
		assert(handle.GetMagic() == magicNumbers_[index]);
		
		magicNumbers_[index] = 0;//0代表句柄为空,合法的句柄的magic~(1 ,2^16-1)
		freeSlots.push_back(index);
	}

	template<typename Data, typename CSHandle>
	inline Data* CSHandleManager<Data, CSHandle>
	::Dereference(CSHandle handle)
	{
		if (handle.IsNull())
		{
			return 0;//!! 0, Null,or nullptr
		}
		unsigned int index = handle.GetIndex();
		if ((index > userData_.size())
			|| (magicNumbers_[index] ！ = handle.GetMagic()))
		{
			assert(0);
			return 0;
		}

		return(userData_.begin() + index);
	}
	template<typename Data, typename CSHandle>
	inline const Data* CSHandleManager<Data, CSHandle>
		::Dereference(CSHandle handle) const
	{
		typedef CSHandleManager<Data, CSHandle> ThisType;
		//const_cast > ->的优先级
		//http://www.cnblogs.com/ider/archive/2011/07/22/cpp_cast_operator_part2.html
		//const_cast,去除const属性，但是不会修改与对象的属性
		//const_cast,之后不可以再改数据，否则会存在未定义行为
		//v[i]=i++;也是未定义行为
		return( const_cast<ThisType*> ( this )->Dereference( handle ) );
	}

}