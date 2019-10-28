#include "std_lib_facilities.h"
#include <set>

class Code {
	vector<string> ans_list;
	set<string> ans_set;
	string str;
	set<string> word_list = { "alignas","alignof","and","and_eq","asm","atomic_cancel","atomic_commit","atomic_noexcept","auto","bitand","bitor","bool","break","case","catch","char","char8_t","char16_t","char32_t","class","compl","concept","const","consteval","constexpr","constinit","const_cast","continue","co_await","co_return","co_yield","decltype","default","define","defined","delete","do","double","dynamic_cast","elif","else","error","endif","enum","explicit","export","extern","false","final","float","for","friend","goto","if","ifdef","ifndef","import","include","inline","int","line","long","module","mutable","namespace","new","noexcept","not","not_eq","nullptr","operator","or","or_eq","override","pragma","private","protected","public","reflexpr","register","reinterpret_cast","requires","return","short","signed","sizeof","static","static_assert","static_cast","struct","switch","synchronized","template","this","thread_local","throw","xor_eq","true","try","typedef","typeid","typename","undef","union","unsigned","using","virtual","void","volatile","wchar_t","while","xor" };
public:
	Code() = default;
	void add(const string& s);
	void parse();
	void print();
};