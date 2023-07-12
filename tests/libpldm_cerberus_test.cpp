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

TEST(MessagingControlRequest, testGetPLDMCommands) {
    uint8_t pldmType = PLDM_FWUP;
    ver32_t version{0xFF, 0xFF, 0xFF, 0xFF};
    std::array<uint8_t, hdrSize + PLDM_GET_COMMANDS_REQ_BYTES>
        requestMsg{};
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_get_commands_req(0, pldmType, version, request);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(0, memcmp(request->payload, &pldmType, sizeof(pldmType)));
    EXPECT_EQ(0, memcmp(request->payload + sizeof(pldmType), &version,
                        sizeof(version)));

}

TEST(MessagingControlRequest, testGetPLDMVersion) {
    uint8_t pldmType = PLDM_BIOS;
    uint32_t transferHandle = 0x0;
    uint8_t opFlag = 0x01;
    std::array<uint8_t, hdrSize + PLDM_GET_VERSION_REQ_BYTES>
        requestMsg{};
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_get_version_req(0, transferHandle, opFlag, pldmType, request);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(0, memcmp(request->payload, &transferHandle, sizeof(transferHandle)));
    EXPECT_EQ(0, memcmp(request->payload + sizeof(transferHandle), &opFlag, sizeof(opFlag)));
    EXPECT_EQ(0, memcmp(request->payload + sizeof(transferHandle) + sizeof(opFlag), 
        &pldmType, sizeof(pldmType)));
}

TEST(MessagingControlRequest, testSetTID) {
    uint8_t tid = 0x24;
    std::array<uint8_t, hdrSize + sizeof(pldm_set_tid_req)> requestMsg{};
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_set_tid_req(0, tid, request);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(0, memcmp(request->payload, &tid, sizeof(tid)));

}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}