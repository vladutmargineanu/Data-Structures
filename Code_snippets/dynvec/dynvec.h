#ifndef __DYNVEC
#define __DYNVEC

template<typename T> class DynamicVector {
	public:
		DynamicVector() {}
		virtual void add_last(T element) = 0;
		virtual void remove_last() = 0;
		virtual int get_element(int position, T& element) = 0;
		virtual int set_element(int position, T element) = 0;
		virtual int size() = 0;
};

#endif
