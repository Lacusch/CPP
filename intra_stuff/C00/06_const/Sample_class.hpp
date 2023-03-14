#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>
class Sample{

public:
	float const pi;
	int			qd;

	Sample(float const f);
	~Sample(void);

	void bar(void) const;
	// this atribute of this instance of the class shoud never be altered

};

#endif