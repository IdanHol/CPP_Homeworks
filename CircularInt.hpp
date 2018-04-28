#include <iostream>
using namespace std;

#include <string>
class CircularInt{
    int max;
    int min;
    int hour;
    public:
    CircularInt(const int& ,const int&);
    CircularInt(int);
    int GetHour() const;
    void setHour(int);
    int GetMin() const;
    int GetMax() const;
    const CircularInt& operator=(const CircularInt&);
    CircularInt& operator+= (const CircularInt&);
    CircularInt& operator+= (const int&);
    CircularInt& operator-= (const int&);
    CircularInt& operator-= (const CircularInt&);
    CircularInt& operator++ ();
    CircularInt operator++ (int);
    CircularInt& operator-- ();
    CircularInt operator-- (int);
    friend const CircularInt operator+ (const CircularInt& ,const CircularInt&);
    friend const CircularInt operator+ (const int,const CircularInt&);
    friend const CircularInt operator+ (const CircularInt&,const int);
    const CircularInt operator-();
    const CircularInt& operator*=(const CircularInt&);
    const CircularInt& operator/=(const CircularInt&);
    const CircularInt& operator%=(const CircularInt&);
    const CircularInt& operator*=(const int&);
    const CircularInt& operator/=(const int&);
    const CircularInt& operator%=(const int&);
    friend const CircularInt operator/(const CircularInt&, const CircularInt&);
    friend const CircularInt operator/(const int, const CircularInt&);
    friend const CircularInt operator/(const CircularInt&,const int);
    friend const CircularInt operator- (const CircularInt&,const CircularInt&);
    friend const CircularInt operator- (const int,const CircularInt&);
    friend const CircularInt operator- (const CircularInt&,const int);
    friend const CircularInt operator*(const CircularInt&, const CircularInt&);
     friend const CircularInt operator*(const int, const CircularInt&);
    friend const CircularInt operator*(const CircularInt&,const int);
    friend const CircularInt operator%(const CircularInt&, const CircularInt&);
    friend const CircularInt operator%(const int, const CircularInt&);
    friend const CircularInt operator%(const CircularInt&,const int);
      friend const CircularInt operator^(const CircularInt&, const CircularInt&);
    friend const CircularInt operator^(const int, const CircularInt&);
    friend const CircularInt operator^(const CircularInt&,const int);
    friend ostream& operator<< (ostream& out, CircularInt);
    friend istream& operator>> (istream& input, CircularInt);
    friend  CircularInt operator>> (CircularInt , int const& );
    friend  CircularInt operator<< (CircularInt , int const& );
    friend  CircularInt operator& (CircularInt , int const& );
    friend bool operator==(int const other,CircularInt const&);
    bool operator== (CircularInt const&);
    bool operator==(int const other);
    friend bool operator!=(int const other,CircularInt const&);
    bool operator!= (CircularInt const&);
    bool operator!= (int const&);
    friend bool operator<=(int const other,CircularInt const&);
    friend bool operator>=(int const other,CircularInt const&);
    friend bool operator<(int const other,CircularInt const&);
    friend bool operator>(int const other,CircularInt const&);
    bool operator> (CircularInt const&);
    bool operator< (CircularInt const&);
    bool operator> (int const&);
    bool operator< (int const&);
    bool operator>= (CircularInt const&);
    bool operator<= (CircularInt const&);
    bool operator! ();
    
};
inline CircularInt operator& (CircularInt c, int const& other){
    CircularInt temp (c);
    temp.hour = temp.hour & other;
    return temp;
}
inline CircularInt operator<< (CircularInt c, int const& other){
    CircularInt temp (c);
    temp.hour = temp.hour << other;
    return temp;
}
inline CircularInt operator>> (CircularInt c, int const& other){
    CircularInt temp (c);
    temp.hour = temp.hour >> other;
    return temp;
}
inline bool operator==(int const other,CircularInt const& c){
     return c.hour==other;
}
inline bool operator!=(int const other,CircularInt const& c){
     return c.hour!=other;
}
inline bool operator>(int const other,CircularInt const& c){
     return other>c.hour;
}
inline bool operator<(int const other,CircularInt const& c){
     return other<c.hour;
}
inline bool operator>=(int const other,CircularInt const& c){
     return other>=c.hour;
}
inline bool operator<=(int const other,CircularInt const& c){
     return other<=c.hour;
}
inline istream&  operator>>(istream& input, CircularInt c){
    int temp;
    input>> temp;
    if(temp>c.GetMax() || temp<c.GetMin())
		throw std::invalid_argument( "The value is not in the range\n" );
    c.setHour(temp);
    return input;

}

inline ostream&  operator<< (ostream& out, CircularInt c){
    out << c.hour;
    return out;

}
inline const CircularInt operator- (const int other,const CircularInt& c){
    CircularInt temp(c);
    temp.hour=other-temp.hour;
        while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
    return temp;
}
inline const CircularInt operator-(const CircularInt& c1,const CircularInt& c2){
    CircularInt temp(c1.hour-c2.hour);
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        while(temp.hour<c1.min){
            temp.hour=temp.hour+(c1.max-c1.min+1);
        }
        while(temp.hour>c1.max){
            temp.hour=temp.hour-(c1.max-c1.min+1);
        }
    }
    else{
        while(temp.hour<c2.min){
            temp.hour=temp.hour+(c2.max-c2.min+1);
        }
        while(temp.hour>c2.max){
            temp.hour=temp.hour-(c2.max-c2.min+1);
        }
    }
    return temp;
}
inline const CircularInt operator- (const CircularInt& c,const int other){
 CircularInt temp(c);
    temp.hour=temp.hour-other;
        while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
    return temp;
}
inline const CircularInt operator+ (const CircularInt& c,const int other){
CircularInt temp(c);
    temp.hour=other+temp.hour;
  while(temp.hour>temp.max)
            temp.hour=temp.hour-(temp.max-temp.min+1);
        return temp;
}
inline const CircularInt operator+ (const int other, const CircularInt& c){
CircularInt temp(c);
    temp.hour=other+temp.hour;
  while(temp.hour>temp.max)
            temp.hour=temp.hour-(temp.max-temp.min+1);
        return temp;
}
inline const CircularInt operator+ (const CircularInt& c1, const CircularInt& c2){
    CircularInt temp(c1.hour+c2.hour);
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        while(temp.hour>c1.max){
            temp.hour=temp.hour-(c1.max-c1.min+1);
        }
        while(temp.hour<c1.min){
            temp.hour=temp.hour+(c1.max-c1.min+1);
        }
    }
    else{
        while(temp.hour>c2.max){
            temp.hour=temp.hour-(c2.max-c2.min+1);
        }
        while(temp.hour<c2.min){
            temp.hour=temp.hour+(c2.max-c2.min+1);
        }
    }
    return temp;
}
inline const CircularInt operator/(const CircularInt& c, const CircularInt& other){
     if(c.hour%other.hour!=0)
            throw string("There is no number x in {"+to_string(c.min)+","+to_string(c.max)+"} such that x*"+to_string(other.hour)+"="+to_string(c.hour));

    CircularInt temp(c);
    bool flag=true;
    int i=temp.min;
        while(i<=temp.max && flag){
            if(i*other.hour == temp.hour){
                temp.hour=i;
                flag=false;
            }
            i++;
        }
             if(flag)
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    return temp;
}
inline const CircularInt operator/(const CircularInt& c,const int other){
       if(c.hour%other!=0)
            throw string("There is no number x in {"+to_string(c.min)+","+to_string(c.max)+"} such that x*"+to_string(other)+"="+to_string(c.hour));

    CircularInt temp(c);
    bool flag=true;
    int i=temp.min;
        while(i<=temp.max && flag){
            if(i*other == temp.hour){
                temp.hour=i;
                flag=false;
            }
            i++;
        }
             if(flag)
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    return temp;
}
inline const CircularInt operator/(const int other,const CircularInt& c){
     if(c.hour%other!=0)
            throw string("There is no number x in {"+to_string(c.min)+","+to_string(c.max)+"} such that x*"+to_string(other)+"="+to_string(c.hour));

    CircularInt temp(c);
    bool flag=true;
    int i=temp.min;
        while(i<=temp.max && flag){
            if(i*other == temp.hour){
                temp.hour=i;
                flag=false;
            }
            i++;
        }
             if(flag)
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    return temp;
}
inline const CircularInt operator*(const CircularInt& c1, const CircularInt& c2){
    CircularInt temp(c1.hour*c2.hour);
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        while(temp.hour>c1.max){
            temp.hour=temp.hour-(c1.max-c1.min+1);
        }
        while(temp.hour<c1.min){
            temp.hour=temp.hour+(c1.max-c1.min+1);
        }
    }
    else{
        while(temp.hour>c2.max){
            temp.hour=temp.hour-(c2.max-c2.min+1);
        }
        while(temp.hour<c2.min){
            temp.hour=temp.hour+(c2.max-c2.min+1);
        }
    }
    return temp;
}
inline const CircularInt operator*(const CircularInt& c,const int other){
    CircularInt temp(c);
    temp.hour=temp.hour*other;
        while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
        while(temp.hour>temp.max)
            temp.hour=temp.hour-(temp.max-temp.min+1);
    return temp;
}
inline const CircularInt operator*(const int other,const CircularInt& c){
    CircularInt temp(c);
    temp.hour=temp.hour*other;
        while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
        while(temp.hour>temp.max)
            temp.hour=temp.hour-(temp.max-temp.min+1);
    return temp;
}


inline const CircularInt operator%(const CircularInt& c1, const CircularInt& c2){
CircularInt temp(c1);
    temp.hour=temp.hour%c2.hour;
   while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
        return temp;
}
inline const CircularInt operator% (const CircularInt& c,const int other){
    CircularInt temp(c);
    temp.hour=temp.hour%other;
        while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
    return temp;
}
inline const CircularInt operator% (const int other,const CircularInt& c){
    CircularInt temp(c);
    temp.hour=other%temp.hour;
        while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
    return temp;
}
inline const CircularInt operator^(const CircularInt& c1, const CircularInt& c2){
CircularInt temp(c1);
    temp.hour=temp.hour^c2.hour;
     while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
    while(temp.hour>temp.max)
            temp.hour=temp.hour-(temp.max-temp.min+1);
        return temp;
}
inline const CircularInt operator^ (const CircularInt& c,const int other){
    CircularInt temp(c);
    temp.hour=temp.hour^other;
       while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
       while(temp.hour>temp.max)
            temp.hour=temp.hour-(temp.max-temp.min+1);
    return temp;
}
inline const CircularInt operator^(const int other,const CircularInt& c){
    CircularInt temp(c);
    temp.hour=other^temp.hour;
        while(temp.hour<temp.min)
            temp.hour=temp.hour+(temp.max-temp.min+1);
        while(temp.hour>temp.max)
            temp.hour=temp.hour-(temp.max-temp.min+1);
    return temp;
}
