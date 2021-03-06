#include "src/SegmentBase.hpp"
#include "gtest/gtest.h"

using namespace CppJieba;

TEST(SegmentBaseTest, Test1)
{
    const char* str = "heheh你好...hh";
    string s;
    vector<string> buf;
    buf.push_back("heheh");
    buf.push_back("你好");
    buf.push_back("...hh");
    vector<string> res;
    uint size = strlen(str);
    uint offset = 0;
    while(offset < size)
    {
        uint len;
        const char* t =  str + offset;
        int ret = SegmentBase::filterAscii(t, size - offset, len);
        s.assign(t, len);
        res.push_back(s);
        //cout<<s<<","<<ret<<","<<len<<endl;
        //cout<<str<<endl;
        offset += len;
    }
    EXPECT_EQ(res, buf);
}

//int main(int argc, char** argv)
//{
//    //ChineseFilter chFilter;
//    return 0;
//}

