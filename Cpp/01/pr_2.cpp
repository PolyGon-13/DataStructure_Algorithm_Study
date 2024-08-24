#include <iostream>
#include <array>
#include <type_traits>

using namespace std;

template<typename... Args>
auto build_array(Args&&... args) -> array<typename common_type <Args...>::type, sizeof...(args)>
{
	using commonType=typename common_type<Args...>::type;
	return {forward<commonType>((Args&&)args)...};
}
// common_type은 여러 자료형들 중에서 가장 일반적인 자료형을 결정 (int와 float가 있으면 float를 반환)
// common_type은 트레이트 자료형으로 type 멤버를 통해 결과 자료형을 제공함
// sizeof...(args)는 파라미터 팩(args)의 요소 개수를 반환


int main()
{
	auto data=build_array(1,0u,'a',3.2f,false);
	
	for(auto i:data)
		cout<<i<<" ";
	cout<<'\n';
	
	return 0;
}
