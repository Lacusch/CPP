
#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

class Sample {

public:

	Sample( void );
	~Sample ( void );

	int get_Foo( void ) const;
	void setFoo ( int v );

private:
	int	_foo;
};

#endif