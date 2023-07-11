#include <string.h>

#include <array>
#include <cstring>
#include <vector>

#include "../base.h"
#include "../utils.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::ElementsAreArray;

constexpr auto hdrSize = sizeof(pldm_msg_hdr);

TEST(GetPLDMCommands, testEncodeRequests) {

}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}