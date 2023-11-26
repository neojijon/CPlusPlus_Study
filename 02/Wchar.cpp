#include <iostream>
#include <locale>
#include <cstring>

int main(void){
  //  	std::wcout << std::wcout.getloc().name().c_str() << std::endl;
  
#if defined __linux__  || defined __CYGWIN__ 
	setlocale(LC_ALL, "ko_KR.utf8");
    std::wcout << L"setlocale(LC_ALL, \"ko_KR.utf8\");" << std::endl;
#elif defined(WIN32) // _WIN32
    std::wcout.imbue( std::locale( "kor" ) );
	std::wcin.imbue( std::locale( "kor" ) ); 
    std::wcout << L"std::wcout.imbue( std::locale(\"kor\"));" << std::endl;
#else
	setlocale(LC_ALL, ""); 
    std::wcout << L"setlocale(LC_ALL, \"Korean\");" << std::endl;	
#endif

	wchar_t en[] = L"Hello World!";
	std::wcout << "wchar_t " << en << L", wchar_t 바이트 크기 : " << sizeof(wchar_t) << std::endl;

    std::wcin >> en;
    std::cout << "std::cout를 사용하면 "; 
	for (int i = 0; en[i] ; ++i) {
        std::cout << (char)en[i];
    }
    std::cout << std::endl;

    std::wcout << L"그러나 std::wcout를 사용하면 \'" << en << "'" << std::endl;
    
	wchar_t wc1[] = L"한글화 작업"; // OK
    std::wcout << wc1 << std::endl;

    int i = 0;	
	while (wc1[i]) {
        std::cout << (char)wc1[i];
        i++;
    }
	std::cout << std::endl;
        
	// const wchar_t *wc2 = L"\u3042 한글화 작업";
    const wchar_t *wc2 = L"\ud55c\uae00화 작업"; 
	std::wcout << wc2  << L", 문자 크기 : " << wcslen(wc2) << std::endl;
	return 0;
}