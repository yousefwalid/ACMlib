string toBinary(int num)
{
	string tmp = "";
	if(!num) tmp = "0";
	while(num) tmp+=( (num&1)+'0'),num>>=1;
	reverse(tmp.begin(),tmp.end());
	return tmp;
}
