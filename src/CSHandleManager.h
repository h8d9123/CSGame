#pragma once
#include	<cassert>
#include<vector>
namespace cs
{
	template<typename Data,typename CSHandle>
	class CSHandleManager
	{
	private:
		typedef std::vector<unsigned int> MagicVec;
		typedef std::vector<unsigned int> FreeVec;
		//Data* or Data ?
		typedef std::vector<Data*> UserVec;

		UserVec userData_;
		MagicVec magicNumbers_;
		FreeVec freeSlots_;
	public:
		CSHandleManager(void) {};
		~CSHandleManager(void) {};

		//alloc
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
			index = freeSlots_.back();
			handle.init(index);
			userData_.pop_back();
			magicNumbers_[index] = hangle.GetMagic();
		}

		return (userData_.begin()+index)
	}
}