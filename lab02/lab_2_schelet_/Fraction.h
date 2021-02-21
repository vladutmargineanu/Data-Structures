#ifndef __FRACTION_H
#define __FRACTION_H

class Fraction {
public:
	double num;
	double denom;

	Fraction(double n, double d): num(n), denom(d) {};

    /* TODO: Overload * operator
    Fraction operator*...{
    }*/
     Fraction operator* ( const Fraction& d){
    	Fraction rezultat (0,1);
    	rezultat.num = num * d.num;
    	rezultat.denom = denom * d.denom;
        return rezultat;
    }

	/* TODO: Overload / operator 
	Fraction operator/...{ 
	}*/
    
     Fraction operator/ (const Fraction& d){
     	Fraction rezultat( 0,1);
     	rezultat.num = num * d.denom;
     	rezultat.denom = denom * d.num;
     	return rezultat;
     }


	/* TODO: Get actual value of this fraction
	double getValue...{
	}*/

     double getValue(){
     	return num/denom;
     }

	/* TODO: Overload << operator - Friend function declaration
    friend std::ofstream &operator<<...*/

     friend std::ostream& operator << (std::ostream& out, const Fraction& d );
};
   


/* TODO: Overload << operator - Friend function implementation 
		Fraction f should be printed as:
			f.num/f.denom\n*/

std::ostream &operator<< (std::ostream& out, const Fraction& d){
   	out << d.num <<"/" <<d.denom <<std::endl;
   	return out;
 }

#endif