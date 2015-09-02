    #include <iostream>     
    using namespace std;     
      
    const int MAXLEN = 100;    
      
    class Integer     
    {  
    private:  
        int is_neg; //�Ƿ�Ϊ��  
        int len; // λ��  
        int s[MAXLEN]; // ��ʾ����������  
        char str[MAXLEN]; //ԭ�ַ���  
      
    public:  
        Integer(const char *string = "")  
        {  
            memset(s,0,MAXLEN*sizeof(int));  
            memset(str,0,MAXLEN*sizeof(char));  
            strcpy(str,string);  
            is_neg = 0;  
            len = strlen(str);     
            for (int i = 0; i < len; i++)     
                s[i] = int(str[len-1-i]) - 48;  
        }  
        Integer & operator=(const Integer & oth)  
        {  
            if(this == &oth) return *this;  
            memset(s,0,MAXLEN*sizeof(int));  
            memset(str,0,MAXLEN*sizeof(char));  
            is_neg = oth.is_neg;  
            len = oth.len;  
            for (int i = 0; i < oth.len; i++)     
                s[i] = oth.s[i];  
            strcpy(str,oth.str);  
            return *this;  
        }  
      
        bool operator==(const Integer & oth)  
        {  
            if(this == &oth) return true;  
            bool ret = true;  
            if(len != oth.len || is_neg != oth.is_neg)  
                ret = false;  
            if(strcmp(str,oth.str)) ret = false;  
            for (int i = 0; i < oth.len; i++)  
            {  
                if(s[i] != oth.s[i]) ret = false;  
            }  
            return ret;  
        }  
      
        bool operator!=(const Integer & oth)  
        {  
            return !(*this == oth);  
        }  
      
        Integer operator+(const Integer & oth)  
        {  
            Integer c;  
            int length = len >= oth.len ? len : oth.len;  
            length += 1; //���ܻ��λ  
            c.len = length;  
            for(int i = 0; i < c.len; i++)  
            {  
                c.s[i] += s[i] + oth.s[i];     
                c.s[i+1] += c.s[i] / 10;     
                c.s[i] = c.s[i] % 10;  
            }  
            while ((c.len > 1) && (c.s[c.len-1] == 0))  c.len--;   
            int k = 0;  
            for(int i = c.len-1; i >= 0; i--)  
            {  
                c.str[k++] = (char)(c.s[i]+48);  
            }  
            return c;  
        }  
      
        Integer operator-(const Integer & oth)  
        {  
            Integer c;  
            int flag = 0;  
      
            if(len > oth.len) flag = 1;  
            else if(len < oth.len) flag = -1;  
            else flag = strcmp(str,oth.str);  
      
            if(flag >= 0)  
            {  
                c.len = len;  
                int borrow = 0;  
                for (int i = 0; i < c.len; i++)  
                {  
                    c.s[i] += s[i] - oth.s[i];  
                    if(borrow) c.s[i] -= 1;  
                    if(c.s[i] < 0)  
                    {  
                        c.s[i] += 10;  
                        borrow = 1;  
                    }  
                    else  
                        borrow = 0;  
                }  
                while ((c.len > 1) && (c.s[c.len-1] == 0))  c.len--;   
            }  
            else  
            {  
                c.is_neg = 1;  
                c.len = oth.len;  
                int borrow = 0;  
                for (int i = 0; i < c.len; i++)  
                {  
                    c.s[i] += oth.s[i] - s[i];  
                    if(borrow) c.s[i] -= 1;  
                    if(c.s[i] < 0)  
                    {  
                        c.s[i] += 10;  
                        borrow = 1;  
                    }  
                    else  
                        borrow = 0;  
                }  
                while ((c.len > 1) && (c.s[c.len-1] == 0))  c.len--;   
            }  
      
            int k = 0;  
            for(int i = c.len-1; i >= 0; i--)  
            {  
                c.str[k++] = (char)(c.s[i]+48);  
            }  
            return c;     
        }  
      
        Integer operator*(const Integer & oth)     
        {  
            Integer c;  
            c.len = len + oth.len + 1;    
            for (int i = 0; i < len; i++)  
            {  
                for (int j = 0; j < oth.len; j++)  
                {  
                    c.s[i+j] += s[i] * oth.s[j];     
                    c.s[i+j+1] += c.s[i+j] / 10;     
                    c.s[i+j] = c.s[i+j] % 10;     
                }  
            }  
            while ((c.len > 1) && (c.s[c.len-1] == 0))  c.len--;  
            int k = 0;  
            for(int i = c.len-1; i >= 0; i--)  
            {  
                c.str[k++] = (char)(c.s[i]+48);  
            }  
            return c;  
        }  
      
        Integer operator/(const Integer & oth)  
        {  
            Integer c("0");  
            int flag = 0;  
      
            if(len > oth.len) flag = 1;  
            else if(len < oth.len) flag = -1;  
            else flag = strcmp(str,oth.str);  
      
            Integer one("1");  
            Integer zero("0");  
            Integer t;  
            if(flag >= 0) //���������ڳ�������һֱ������  
            {  
                while(this->is_neg == 0 && *this != zero)  
                {  
                    t = *this - oth;  
                    *this = t;  
                    c = c + one;  
                }  
            }  
            else //������С�ڳ�������Ϊ0  
            {  
                int k = 0;  
                for(int i = c.len-1; i >= 0; i--)  
                {  
                    c.str[k++] = (char)(c.s[i]+48);  
                }  
                return c;  
            }  
      
            int k = 0;  
            for(int i = c.len-1; i >= 0; i--)  
            {  
                c.str[k++] = (char)(c.s[i]+48);  
            }  
            return c;     
        }  
      
        friend ostream & operator<<(ostream & out, const Integer & oth)  
        {  
            if(oth.is_neg) out<<"-";  
            for (int k = oth.len-1; k >= 0; k--)     
                out<<oth.s[k];  
            return out;   
        }  
    };  
      
    int main()     
    {  
        Integer c;  
        char s1[MAXLEN],s2[MAXLEN]; 
		char cases;
      
        cin >> s1 >> cases >> s2; 
      
        Integer a(s1);  
        Integer b(s2);  
		
		switch(cases)
		{

		case '+':c = a+b;  
        cout<<"The plus result is : "<<c<<endl;  break;
      
		case '-':c = a-b;  
        cout<<"The minus result is : "<<c<<endl;  break;
      
      
		case '*':c = a*b;  
        cout<<"The multipy result is : "<<c<<endl;  break;
      
		case '/':c = a/b;  
        cout<<"The divide result is : "<<c<<endl;  break;
		}
      
        return 0;     
    }     