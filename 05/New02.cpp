#define  _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstring>
#include <iostream>

class MyString {
public:
    char* mData;
    size_t mLength;

    const char* GetData() const { return mData; }
};

int main(void) {
    const char* mString = "new 연산자와 malloc() 함수의 차이";
    size_t len = strlen(mString) + 1;

    MyString* s2 = new MyString();
    s2->mData = new char[len];

    memcpy(s2->mData, mString, len);
    printf("s2 포인터 : 0x%p, s2->mData 포인터 : 0x%p\n문자 : %s\n",
        s2, s2->GetData(), s2->GetData());
    delete s2->mData;
    delete s2;

    size_t n = sizeof(MyString);
    std::cout << n << std::endl;

    MyString* s3 = (MyString*)malloc(n);
    if (nullptr == s3) {
        printf("s3 포인터가 NULL를 반환하였습니다.\n");
        return 1;
    }

    char* p = (char*)malloc(len);
    if (nullptr != p) {
        s3->mData = p;
        memcpy(s3->mData, mString, len);

        printf("s3 포인터 : 0x%p, s3->mData 포인터 : 0x%p\n문자 : %s\n",
            s3, s3->GetData(), s3->GetData());
        free(s3->mData);
        free(s3);
    }  
    return 0;
}
