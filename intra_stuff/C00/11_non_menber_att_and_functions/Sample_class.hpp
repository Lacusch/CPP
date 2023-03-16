
#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

class Sample {

public:

	Sample( void );
	~Sample ( void );

	static int get_Nb_inst( void );

private:
	static	int	_nbInst;
};

#endif