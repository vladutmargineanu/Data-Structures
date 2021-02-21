template<typename T> class Sorter {
	protected:
	T* v;
	int N;
	int (*compare) (T,T);
	
	public:
	Sorter(T* v, int N, int (*compare)(T,T)) {
		this->v = v;
		this->N = N;
		this->compare = compare;
	}
	
	virtual void sort() = 0;
};

