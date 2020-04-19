#include "googletest/include/gtest/gtest.h"
#include "median_structure.h"

TEST(MedianTest, EmptyQueuesTest)
{
    MedianStructure m;
    EXPECT_EQ(0, m.getMedian());
}

TEST(MedianTest, OneNumberTest)
{
    MedianStructure m;
    m.addNumber(10);
    EXPECT_EQ(10, m.getMedian());
    EXPECT_EQ(1, m.lowerContainerSize());
    EXPECT_EQ(0, m.higherContainerSize());
}

TEST(MedianTest, LowerContainerSizeAdjustmentTest)
{
    MedianStructure m;
    m.addNumber(10);
    m.addNumber(5);
    EXPECT_EQ(7.5, m.getMedian());
    EXPECT_EQ(1, m.lowerContainerSize());
    EXPECT_EQ(1, m.higherContainerSize());
}

TEST(MedianTest, HigherContainerSizeAdjustmentTest)
{
    MedianStructure m;

    for (int n : {10, 15, 17, 19})
        m.addNumber(n);

    EXPECT_EQ(16, m.getMedian());
    EXPECT_EQ(2, m.lowerContainerSize());
    EXPECT_EQ(2, m.higherContainerSize());
}

TEST(MedianTest, NumberEqualToMedianTest_ShouldAddToSmallerContainer)
{
    MedianStructure m;

    for (int n : {10, 4, 2, 4})
        m.addNumber(n);

    EXPECT_EQ(4, m.getMedian());
    EXPECT_EQ(2, m.lowerContainerSize());
    EXPECT_EQ(2, m.higherContainerSize());
}

TEST(MedianTest, NumberEqualToMedianTest_ShouldAddToLowerContainer)
{
    MedianStructure m;

    for (int n : {5, 3, 10, 15})
        m.addNumber(n);

    m.addNumber(m.getMedian());

    EXPECT_EQ(3, m.lowerContainerSize());
    EXPECT_EQ(2, m.higherContainerSize());
    EXPECT_EQ(7.5, m.getMedian());
}

TEST(MedianTest, CheckMedianAndContainerSizes)
{
    MedianStructure m;
    for(auto n : {1, 3, 22, 4, 15, 10})
        m.addNumber(n);

    EXPECT_EQ(7, m.getMedian());
    EXPECT_EQ(m.lowerContainerSize(), m.higherContainerSize());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
