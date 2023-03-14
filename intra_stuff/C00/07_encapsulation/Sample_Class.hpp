
#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class Sample {

public:
	int publicFOO;

	Sample ( void );
	~Sample (void);

	void publicBar (void ) const;

private:
	int	_prinvateFoo ;

	void _private_Bar (void) const ;
};
#endif