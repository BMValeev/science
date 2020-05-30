#include <QtTest>

// add necessary includes here

class TestUtils : public QObject
{
    Q_OBJECT

public:
    TestUtils();
    ~TestUtils();

private slots:
    void test_case1();

};

TestUtils::TestUtils()
{

}

TestUtils::~TestUtils()
{

}

void TestUtils::test_case1()
{

}

QTEST_APPLESS_MAIN(TestUtils)

#include "tst_testutils.moc"
