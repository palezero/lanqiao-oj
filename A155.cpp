ostream& operator<<(ostream& os, const zrf_Ratio& zrf_Ratio)  
{  
    os << zrf_Ratio.num << "/" << zrf_Ratio.den;  
    return os;
}
istream& operator>>(istream& in, zrf_Ratio& zrf_Ratio)
{
	in >> zrf_Ratio.num >> zrf_Ratio.den;
	return in;
}
bool operator==(const zrf_Ratio& zrf_Ratio1, const zrf_Ratio& zrf_Ratio2)
{
	if( zrf_Ratio1.num * zrf_Ratio2.den == zrf_Ratio1.den * zrf_Ratio2.num)
		return 1;
	return 0;
}
bool operator<(const zrf_Ratio& zrf_Ratio1, const zrf_Ratio& zrf_Ratio2)
{
	if( zrf_Ratio1.num*1.0 / zrf_Ratio1.den < zrf_Ratio2.num*1.0 / zrf_Ratio2.den )
		return 1;
	return 0;
}
