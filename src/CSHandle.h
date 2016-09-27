#pragma once
#include <cassert>
#include <vector>
namespace cs
{
	/**
	*1-p59
	*�پ������T��ֻ���������־���İ�ȫ�ԣ����ڲ���û��ʹ��
	*�����ͬ�ľ������ת���ᷢ���������
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
		*�˴����ó�Ա�����ڲ��ľ�̬����
		*�����̬����ֻ���ڸú����������Ա�ľ�̬������ͬ
		*������������������ʵ������ֻҪ����������������ͻ�ı����
		*static �������൱����ʵ���Ĺ����������c�����еľ�̬�ڲ���Ա��ͬ
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
