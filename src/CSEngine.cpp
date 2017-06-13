template<T>
class CSVector3
{
public:
	//Holds value along x, y, z axis;
	T x;
	T y;
	T z;
private:
	//padding to ensure 4-word alignment
	T pad;
public:
	CSVector3():x(0),y(0),z(0){}
	CSVector3(const T x,const T y,const T z) :x(x), y(y), z(z){}
	void invert()
	{
		x = -x;
		y = -y;
		z = -z;
	}
};