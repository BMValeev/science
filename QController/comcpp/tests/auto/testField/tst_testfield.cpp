#include <QtTest>

#include "smartcontrol/record.h"

Q_DECLARE_METATYPE(std::string)

class TestField : public QObject
{
    Q_OBJECT

public:

private slots:
    void test_assigment();
    void test_bool();
    void test_int8();
    void test_int8_data();
    void test_uint8();
    void test_uint8_data();
    void test_int16();
    void test_int16_data();
    void test_uint16();
    void test_uint16_data();
    void test_int32();
    void test_int32_data();
    void test_uint32();
    void test_uint32_data();
    void test_float();
    void test_float_data();
    void test_StdString();
    void test_StdString_data();
    // void test_QByteArray();
    // void test_QByteArray_data();
    void test_raw();
    void test_raw_data();
    void test_QString();
    void test_QString_data();
};

void TestField::test_assigment()
{
    Field f(0.1);
    QCOMPARE(static_cast<float>(f), 0.1f);
    f = 0.2;
    QCOMPARE(static_cast<float>(f), 0.2f);
    f = 23;
    QCOMPARE(static_cast<int8_t>(f), int8_t(23));
    QCOMPARE(static_cast<uint8_t>(f), uint8_t(23));
    QCOMPARE(static_cast<int16_t>(f), int16_t(23));
    QCOMPARE(static_cast<uint16_t>(f), uint16_t(23));
    QCOMPARE(static_cast<int32_t>(f), int32_t(23));
    QCOMPARE(static_cast<uint32_t>(f), uint32_t(23));
    f = -23;
    QCOMPARE(static_cast<int8_t>(f), int8_t(-23));
    QCOMPARE(static_cast<int16_t>(f), int16_t(-23));
    QCOMPARE(static_cast<int32_t>(f), int32_t(-23));
}

void TestField::test_bool()
{
    Field f(false);
    QCOMPARE(static_cast<bool>(f), false);
    f = true;
    QCOMPARE(static_cast<bool>(f), true);
}

void TestField::test_int8()
{
    QFETCH(int8_t, input);

    Field f(input);
    QCOMPARE(static_cast<int8_t>(f), input);
}

void TestField::test_int8_data()
{
    QTest::addColumn<int8_t>("input");

    QTest::newRow("positive value") << int8_t(42);
    QTest::newRow("negative value") << int8_t(-42);
    QTest::newRow("zero") << int8_t(0);
}

void TestField::test_uint8()
{
    QFETCH(uint8_t, input);

    Field f(input);
    QCOMPARE(static_cast<uint8_t>(f), input);
}

void TestField::test_uint8_data()
{
    QTest::addColumn<uint8_t>("input");

    QTest::newRow("< 128 value") << uint8_t(42);
    QTest::newRow("> 128 value") << uint8_t(156);
    QTest::newRow("zero") << uint8_t(0);
}

void TestField::test_int16()
{
    QFETCH(int16_t, input);

    Field f(input);
    QCOMPARE(static_cast<int16_t>(f), input);
}

void TestField::test_int16_data()
{
    QTest::addColumn<int16_t>("input");

    QTest::newRow("positive value") << int16_t(16000);
    QTest::newRow("negative value") << int16_t(-16000);
    QTest::newRow("zero") << int16_t(0);
}

void TestField::test_uint16()
{
    QFETCH(uint16_t, input);

    Field f(input);
    QCOMPARE(static_cast<uint16_t>(f), input);
}

void TestField::test_uint16_data()
{
    QTest::addColumn<uint16_t>("input");

    QTest::newRow("< 32767 value") << uint16_t(16000);
    QTest::newRow("> 32767 value") << uint16_t(48000);
    QTest::newRow("zero") << uint16_t(0);
}

void TestField::test_int32()
{
    QFETCH(int32_t, input);

    Field f(input);
    QCOMPARE(static_cast<int32_t>(f), input);
}

void TestField::test_int32_data()
{
    QTest::addColumn<int32_t>("input");

    QTest::newRow("positive value") << int32_t(1000000);
    QTest::newRow("negative value") << int32_t(-1000000);
    QTest::newRow("zero") << int32_t(0);
}

void TestField::test_uint32()
{
    QFETCH(uint32_t, input);

    Field f(input);
    QCOMPARE(static_cast<uint32_t>(f), input);
}

void TestField::test_uint32_data()
{
    QTest::addColumn<uint32_t>("input");

    QTest::newRow("< 2,147,483,647 value") << uint32_t(1000000);
    QTest::newRow("> 2,147,483,647 value") << uint32_t(3000000000);
    QTest::newRow("zero") << uint32_t(0);
}

void TestField::test_float()
{
    QFETCH(float, input);

    Field f(input);
    QCOMPARE(static_cast<float>(f), input);
}

void TestField::test_float_data()
{
    QTest::addColumn<float>("input");

    QTest::newRow("positive value") << float(0.5);
    QTest::newRow("negative value") << float(-0.5);
    QTest::newRow("zero")           << float(0);
}

void TestField::test_StdString()
{
    QFETCH(std::string, input);
    QFETCH(std::string, expected);

    Field f(input);
    QCOMPARE(f.toStdString(), expected);
}

void TestField::test_StdString_data()
{
    qRegisterMetaType<std::string>();
    QTest::addColumn<std::string>("input");
    QTest::addColumn<std::string>("expected");

    QTest::newRow("1 character string") << std::string("a")     << std::string("a");
    QTest::newRow("2 character string") << std::string("ab")    << std::string("ab");
    QTest::newRow("3 character string") << std::string("abc")   << std::string("abc");
    QTest::newRow("4 character string") << std::string("abcd")  << std::string("abcd");
    QTest::newRow("5 character string") << std::string("abcde") << std::string("abcd");
}

// void TestField::test_QByteArray()
// {
//     QFETCH(QByteArray, input);
//     QFETCH(QByteArray, expected);
//
//     Field f(input);
//     QCOMPARE(f.toQByteArray(), expected);
// }
//
// void TestField::test_QByteArray_data()
// {
//     qRegisterMetaType<QByteArray>();
//     QTest::addColumn<QByteArray>("input");
//     QTest::addColumn<QByteArray>("expected");
//
//     QTest::newRow("1 character string") << QByteArray("a")     << QByteArray("a");
//     QTest::newRow("2 character string") << QByteArray("ab")    << QByteArray("ab");
//     QTest::newRow("3 character string") << QByteArray("abc")   << QByteArray("abc");
//     QTest::newRow("4 character string") << QByteArray("abcd")  << QByteArray("abcd");
//     QTest::newRow("5 character string") << QByteArray("abcde") << QByteArray("abcd");
// }

void TestField::test_raw()
{
    QFETCH(QByteArray, input);
    QFETCH(QByteArray, expected);

    Field f(input);
    QCOMPARE(f.raw(), expected);
}

void TestField::test_raw_data()
{
    qRegisterMetaType<QByteArray>();
    QTest::addColumn<QByteArray>("input");
    QTest::addColumn<QByteArray>("expected");

    QTest::newRow("1 character string") << QByteArray("a")     << QByteArray("a\000\000\000", 4);
    QTest::newRow("2 character string") << QByteArray("ab")    << QByteArray("ab\000\000", 4);
    QTest::newRow("3 character string") << QByteArray("abc")   << QByteArray("abc\000", 4);
    QTest::newRow("4 character string") << QByteArray("abcd")  << QByteArray("abcd");
    QTest::newRow("5 character string") << QByteArray("abcde") << QByteArray("abcd");
}

void TestField::test_QString()
{
    QFETCH(QString, input);
    QFETCH(QString, expected);

    Field f(input);
    QCOMPARE(f.toQString(), expected);
}

void TestField::test_QString_data()
{
    qRegisterMetaType<QString>();
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("expected");

    QTest::newRow("1 character string") << QString("a")     << QString("a");
    QTest::newRow("2 character string") << QString("ab")    << QString("ab");
    QTest::newRow("3 character string") << QString("abc")   << QString("abc");
    QTest::newRow("4 character string") << QString("abcd")  << QString("abcd");
    QTest::newRow("5 character string") << QString("abcde") << QString("abcd");
}

QTEST_APPLESS_MAIN(TestField)
#include "tst_testfield.moc"
