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
// Args는 여러 개의 타입을 받을 수 있는 파라미터 팩으로 선언됨
// &&는 포워딩 참조(rvalue와 lvalue 모두 처리 가능 -> &와 &&를 이용하여 rvalue와 lvalue를 다르게 처리할 수 있음)
// -> 는 후행 리턴 타입으로 함수의 반환형을 뒤에 쓸 수 있음 (auto 함수이름(매개변수) -> 반환형)
// common_type은 여러 자료형들 중에서 가장 일반적인 자료형을 결정 (int와 float가 있으면 float를 반환)
// common_type은 트레이트 자료형으로 type 멤버를 통해 결과 자료형을 제공함
// sizeof...(args)는 파라미터 팩(args)의 요소 개수를 반환
// using은 별칭 지정 함수
// 완벽전달을 위해 (Args&&)args처럼 형 변환 진행
// ...에 의해 args라는 파라미터 팩을 각각의 인자들로 풀어서 forward함수로 전달

int main()
{
	auto data=build_array(1,0u,'a',3.2f,false); // int, unsinged int, char, float, bool이므로 위 함수에서 common_type은 float
	
	for(auto i:data)
		cout<<i<<" ";
	cout<<'\n';
	
	return 0;
}
