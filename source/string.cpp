#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "string.hpp"

String::String(){
	array = new char[1];
	array[0] = '\0';
	length = 1;
}

String::String(char *str){

	for(length = 0; array[length]; ++length);

	array = new char[length+1];
	for(int i = 0; i <= length; ++i) //this is only here for strings, never for int arrays
		array[i] = str[i];
}

String::String(char c){
    length = 1;
	array = new char[length + 1];
    array[0] = c;
    array[1] = '\0';
}

String::~String(){
    delete [] array;
}

//O(N)
char String::at(int x) const{
    char q;
    if(x < 0 || x > length){
        throw "error";
    }
    else{
        return array[x];
    }
}

//O(1)
bool String::empty() const{
    if(length == 0){
        return true;
    }
    else{
        return false;
    }
}

//O(1)
unsigned int String::size() const{
   return length;
}

//O(N)
unsigned int String::capacity() const{
    int x;

    for(int i = 0; i < length; i++){
        x++;
    }
    return x;
}

//O(N)
void String::reserve(unsigned int x){

	char *new_arr = new char[length+x+1];

	for(int i = 0; i < length; ++i) new_arr[i] = array[i];

	delete[] array;
	array = new_arr;

}

//O(N)
void String::insert(char c, int x){

	char *new_arr = new char[length];
    for(int i = 0; i < length; i++){
        if(i != x){
            new_arr[i] = array[i];
        }
        else{
            new_arr[i] = c;
        }
    }
}

//O(N)
void String::erase(char c){
	char *new_arr = new char[length+2];
	for(int i = 0; i < length; ++i){
		if(array[i] != c){
			new_arr[i] = array[i];
		}
	}
}

//O(N)
void String::remove(int x){

    char *new_arr = new char[length+1];
    for(int i = 0; i < length; ++i){
        if(i != x){
            new_arr[i] = array[i];
        }
    }

    delete [] array;
    array = new_arr;
}

//O(N)
void String::append(char c){
	char *new_arr = new char[length+2];

	for(int i = 0; i < length; ++i) new_arr[i] = array[i];

	new_arr[length] = c;
	new_arr[length+1] = '\0';

	delete[] array;
	array = new_arr;
}

//O(N)
void String::prepend(char c){

	char *new_arr = new char[length+2];
    new_arr[0] = c;

	for(int i = 1; i < length; ++i) new_arr[i] = array[i];


	new_arr[length+1] = '\0';

	delete[] array;
	array = new_arr;
}

//O(1)
bool String::compare(char *c) const{
    for(int i = 0; i < length; i++){
        if(array[i] != *c){
            return false;
        }
    }
    return true;
}

//O(N)
bool String::compare(String &str) const{
    for(int i = 0; i < length; i++){
        if(array[i] != array[i]){
            return false;
        }
    }
    return true;
}

//O(N)
void String::concatenate(char *c){

    char *new_arr = new char[length+2];

	for(int i = 0; i < length; ++i) new_arr[i] = array[i];

	new_arr[length] = *c;
	new_arr[length+1] = '\0';

	delete[] array;
	array = new_arr;

}

//O(N)
void String::concatenate(String &str){
    for(int i = 0; i < (length + str.size()); i++){
        str.append(array[i]);
    }
}

//O(N)
unsigned int String::find(char* c, int start) const{
    for(int i = 0; i < length; i++){
        if(array[i] == *c){
            return i;
        }
    }
    return 0;
}

//O(N)
unsigned int String::find(char c, int start) const{
    for(int i = 0; i < length; i++){
        if(array[i] == c){
            return i;
        }
    }

    return 0;
}

//O(N)
unsigned int String::find(String &str, int start) const{
    for(int i = 0; i < str.size(); i++){
        if(str.at(i) == array[i]){
            return str.at(i);
        }
    };
    return length;
}

//O(N)
void String::reverse(){


	char *new_arr = new char[length+1];

	for(int i = length; i > length; --i) new_arr[i] = array[i];

	new_arr[length+1] = '\0';

	delete[] array;
	array = new_arr;

}

//O(N)
void String::shift(int x){

    char *new_arr = new char[length+1];

    for(int i = 0; i < length; i++){
        int q = chartoint(array[i]) + x;
        new_arr[i] = inttochar(q);
    }

    new_arr[length+1] = '\0';

	delete[] array;
	array = new_arr;

}

//O(N)
int String::toInt() const{
    int result = 0;
    for(int i = 0; i < length; i++){
        result += (int)array[i];
    }
    return result;
}

//O(N)
String String::substr(int x, int y) const{
	unsigned int length = y-x;

	char *new_arr = new char[length+1];
	for(int i = x; i < y; i++){
		new_arr[i] = array[i];
	}
	return new_arr;


}

//O(1)
int String::chartoint(char c) {
  int result = (int)c;
  result -= '0';
  return result;
}

//O(1)
char String::inttochar(int x) {
  return (char)(x + '0');
}