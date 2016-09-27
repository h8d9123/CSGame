#pragma once
#include <cassert>
#include <vector>
namespace cs
{
	/**
	*1-p59
	*再句柄类中T，只是用来区分句柄的安全性，在内部并没有使用
	*如果不同的句柄进行转换会发生编译错误
	*/
	template <typename T>
	class CSHandle
	{
		union
		{
			enum
			{
				//size of bit fields
				MAX_BITS_INDEX = 16,

				MAX_BITS_MAGIC = 16,
				//used to compares handle, when dereference
				MAX_INDEX = (1 << MAX_BITS_INDEX) - 1,
				MAX_MAGIC = (1 << MAX_BITS_MAGIC) - 1,
			};
			struct
			{
				unsigned index_ : MAX_BITS_INDEX;
				unsigned	 magic_ : MAX_BITS_MAGIC;
			};
			unsigned int handle_;
		};
	public:
		CSHandle(void) :handle_(0) {};
		void Init(unsigned int index);
		bool IsNull(unsigned int index);
		unsigned int GetIndex(void) const { return index_ };
		unsigned int GetMagic(void) const { return magic_ };
		unsigned int GetHandle(void) const { return handle_ };

		operator unsigned int(void) const { return handle_ };

	};
	template<typename T>
	void CSHandle<T>::Init(unsigned int index)
	{
		assert(IsNull());
		assert(index <= MAX_INDEX);
		/**
		*此处采用成员函数内部的静态变量
		*这个静态变量只属于该函数，与类成员的静态变量不同
		*但是属于所有这个类的实例，即只要这个类调用这个函数就会改变这个
		*static 变量，相当于类实例的共享变量，和c语言中的静态内部成员相同
		*/

		static unsigned int sAutoMagic = 0;
		if (++sAutoMagic > MAX_MAGIC)
		{
			sAutoMagic = 1; 
		}
		index_ = index;
		magic_ = sAutoMagic;
	}

	template<typename T>
	inline bool operator!=(CSHandle<T> handle1, CSHandle<T> handle2)
	{
		return (handle1.GetHandle() != handle2.GetHandle());
	}
	template<typename T>
	inline bool operator == (CSHandle<T> handle1, CSHandle<T> handle2)
	{
		return (handle1.GetHandle() == handle2.GetHandle());
	}

}
