#ifndef __GRADEBOOK_H__
#define __GRADEBOOK_H__

class Gradebook {
private:
	double *grades;
	int capacity; // max number of grades
	int count;    // current number of grades

public:
	Gradebook(int capacity) {
		// TODO initialize grades, capacity and count
	}

	~Gradebook() {
		// TODO free memory
	}

	void addGrade(double grade) {
		// TODO add new grade to grades array (if it reaches its capacity return)
	}

	double average() {
		// TODO compute average of the grades that have been added
	}
};

#endif // __GRADEBOOK_H__
