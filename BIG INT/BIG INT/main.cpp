#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 100;

class BigCount
{
private:
	int is_neg;		//是否为负数
	int len;		//整数位数
	int num[MAX * 2];	//数组转化为整数
	char str[MAX * 2];	//原数组
public:
	BigCount(const char *string = ""){
		int i,j;
		memset(num,0,MAX*2*sizeof(int));
		memset(str,0,MAX*2*sizeof(char));
		is_neg = 0;
		strcpy(str,string);		//不能使用strcpy_s!
		len = strlen(str);
		for(i = 0,j = len - 1;j >= 0;i++,j--){
			num[i] = int(str[j] - '0');
		}
	}

	BigCount & operator=(const BigCount & sample){
		if(this == &sample){
		return *this;
		}
		memset(num,0,MAX*2*sizeof(int));
		memset(str,0,MAX*2*sizeof(char));
		is_neg = sample.is_neg;
		len = sample.len;
		for(int i = 0;i < len;i++){
			num[i] = sample.num[i];
		}
		strcpy(str,sample.str);
		return *this;
	}
	
	bool operator==(const BigCount & sample){
		if(this == &sample){
			return true;
		}
		bool ans = true;
		if(len != sample.len || is_neg != sample.is_neg){
			ans = false;
		}
		if(strcmp(str,sample.str)) {
			ans = false;
		}
		for(int i = 0;i < len;i++){
			if(num[i] != sample.num[i]){
				ans = false;
				break;
			}
		}
		return ans;
	}
 
	bool operator!=(const BigCount & sample){
		return !(*this == sample);
	}

	BigCount operator+(const BigCount & sample){	//直接上BigCount sample也可
		BigCount result;
		int maxlong;
		maxlong = len >= sample.len ? len : sample.len;
		maxlong += 1;
		result.len = maxlong;
		for(int i = 0;i < maxlong;i++){
			result.num[i] += num[i] + sample.num[i];
			if(result.num[i] >= 10){
				result.num[i + 1]++;
				result.num[i] -= 10;
			}
		}
		while((result.len > 1) && (result.num[result.len - 1] == 0)){
			result.len--;
		}
		int k = 0;
		for(int i = result.len - 1;i >= 0;i--,k++){
			result.str[k] = char(result.num[i] + '0');
		}
		return result;
	}

	BigCount operator-(const BigCount & sample){
		BigCount result;
		int NegFlag = 0;
		if(len > sample.len){
			NegFlag = 1;
		}
		else if(len < sample.len){
			NegFlag = -1;
		}
		else{
			NegFlag = strcmp(str,sample.str);
		}

		if(NegFlag >= 0){
			result.len = len;
			for(int i = 0;i < len;i++){
				result.num[i] += num[i] - sample.num[i];
				if(result.num[i] < 0){
					result.num[i + 1]--;
					result.num[i] += 10;
				}
			}
			while((result.len > 1) && (result.num[result.len - 1] == 0)){
			result.len--;
			}
		}

		if(NegFlag < 0){
			result.len = sample.len;
			result.is_neg = 1;
			for(int i = 0;i < result.len;i++){
				result.num[i] += sample.num[i] - num[i];
				if(result.num[i] < 0){
					result.num[i + 1]--;
					result.num[i] += 10;
				}
			}
			while((result.len > 1) && (result.num[result.len - 1] == 0)){
			result.len--;
			}
		}
		int k = 0;
		for(int i = result.len - 1;i >= 0;i--,k++){
			result.str[k] = char(result.num[i] + '0');
		}
		return result;
	}

	BigCount operator*(const BigCount & sample){
		BigCount result;
		result.len = len + sample.len + 1;
		for(int i = 0;i < len;i++){
			for(int j = 0;j < sample.len;j++){
				result.num[i + j] += sample.num[j] * num[i];
				result.num[i + j + 1] += result.num[i + j] / 10;
				result.num[i + j] = result.num[i + j] % 10;
			}
		}
		while((result.len > 1) && (result.num[result.len - 1] == 0)){
			result.len--;
			}
		int k = 0;
		for(int i = result.len - 1;i >= 0;i--,k++){
			result.str[k] = char(result.num[i] + '0');
		}
		return result;
	}

	BigCount operator/(const BigCount & sample){
		BigCount result("0");
		BigCount zero("0");
		BigCount one("1");
		BigCount ten("10");
		BigCount t;
		BigCount tempnum;
		BigCount add;
		int NegFlag = 0;
		int shiftlong;
		if(len > sample.len){
			NegFlag = 1;
		}
		else if(len < sample.len){
			NegFlag = -1;
		}
		else{
			NegFlag = strcmp(str,sample.str);
		}

		if(NegFlag < 0){
			return zero;
		}
		else if(NegFlag == 0 && len == 1 && num[0] == 0){
			return zero;
		}
		else if(NegFlag == 0){
			return one;
		}
		else{
			shiftlong = len - sample.len;
			while(shiftlong >= 0){
				tempnum = sample;
				for(int i = 0;i < shiftlong;i++){
					tempnum = tempnum * ten;
				}
				//printf("     %s\n",tempnum.str);
				//printf("     %s\n",str);
				while(len >= tempnum.len){
					if(len == tempnum.len){
						if(strcmp(str,tempnum.str) < 0){
							break;
						}
					}
					t = *this - tempnum;
					*this = t;
					add = one;
					for(int j = 0;j < shiftlong;j++){
						add = add * ten;
					}
					//printf("   %s\n",add.str);
					//printf("   %s\n",this -> str);
					result = result + add;
				}
				shiftlong -= 1;
			}
		}
		int k = 0;
		for(int i = result.len - 1;i >= 0;i--,k++){
			result.str[k] = char(result.num[i] + '0');
		}
		return result;
	}


			

	friend ostream & operator<<(ostream & out,const BigCount & sample){
		if(sample.is_neg == 1){
			out << "-";
		}
		for(int i = 0;i <= sample.len;i++){
			out << sample.str[i];
		}
		return out;
	}


};

int main()
{
	BigCount big;
	char s1[MAX],s2[MAX];
	char mark;
	cin >> s1 >> mark >> s2;
	BigCount a(s1);
	BigCount b(s2);
	switch(mark)
	{
		case '+': big = a+b;break;
		case '-': big = a-b;break;
		case '*': big = a*b;break;
		case '/': big = a/b;break;
	}
	cout << big << endl;
	return 0;
}