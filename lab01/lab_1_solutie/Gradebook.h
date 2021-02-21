#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H

class Gradebook {
	private:
		double *grades;
		int capacity;
		int count;
	public:
		Gradebook(int capacity) {
			this -> capacity = capacity;
			count = 0;
			grades = new double[capacity];
		}
		~Gradebook() {
			delete[] grades;
		}
		void addGrade(double grade) {
			if (count == capacity) {
				return;
			}
			grades[count] = grade;
			count++;
		}
		double average() {
			double sum = 0;
			for (int i = 0; i < count; i++) {
				sum += grades[i];
			}
			return sum / count;
		}	
};
#endif
