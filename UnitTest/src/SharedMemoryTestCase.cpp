#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Writer.h>
#include <Reader.h>

namespace tsmtest
{
    using namespace tsm;

    TEST(Writer, write_read_float)
    {
        auto writer = Writer<float>("testdata", 128);
        std::vector<float> data;
        for (auto i = size_t{ 0 }; i < 128; ++i)
            data.push_back(static_cast<float>(i));

        writer.write(&data[0]);

        auto reader = Reader<float>("testdata", 128);

        auto&& dataPtr = reader.get();

        for (auto i = size_t{ 0 }; i < 128; ++i)
            EXPECT_EQ(i, dataPtr[i]);
    }

    TEST(Writer, writer_duplication_allowed)
    {
        auto writer1 = Writer<float>("testdata", 128);
        EXPECT_NO_THROW(auto writer2 = Writer<float>("testdata", 128));

    }

    TEST(Reader, reader_duplication_allowed)
    {
        auto writer = Writer<float>("testdata", 128);

        auto reader1 = Reader<float>("testdata", 128);
        EXPECT_NO_THROW(auto reader = Writer<float>("testdata", 128));
    }
}

