#pragma once
#include	<cassert>
#include<vector>

//#include "CSHandle.h"
namespace cs
{
	/**
	*1-p60
	*1.Data���Ͳ���һ�������ϵ�C++�࣬��Ӧ�þ�������κ���Ҫ�����Ĺ��캯����
	*  �����������������Դ���ͷ���Դ
	*2.�������ڲ�ʹ�õ���Data,������ָ��
	*  ָ�������¼���ʱ��Ϣ�Ѿ���ʧ�����Կ��ԷŶ�����vector���Լ�¼״̬��Ϣ
	*3.����಻Ӧ�ñ��ͻ�����ʹ�ã�Ӧ�ö����װ��ʹ�ã��������
	*4.�����ͷ�ʱindex�������˿����б��У�Data�������������������Ա��ظ����ã����ұ�֤
	*  ��������ظ�����Ӧ��dataֻ��Ҫ����ʼ������
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
		//�б�Ϊ��
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
			//�ӿ����б���ȡ��index,indexһ�����ظ���
			//���Ϊ�գ�˵��0-magicNumbers-1�Ѿ���ʹ����
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
		
		magicNumbers_[index] = 0;//0������Ϊ��,�Ϸ��ľ����magic~(1 ,2^16-1)
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
			|| (magicNumbers_[index] �� = handle.GetMagic()))
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
		//const_cast > ->�����ȼ�
		//http://www.cnblogs.com/ider/archive/2011/07/22/cpp_cast_operator_part2.html
		//const_cast,ȥ��const���ԣ����ǲ����޸�����������
		//const_cast,֮�󲻿����ٸ����ݣ���������δ������Ϊ
		//v[i]=i++;Ҳ��δ������Ϊ
		return( const_cast<ThisType*> ( this )->Dereference( handle ) );
	}

}