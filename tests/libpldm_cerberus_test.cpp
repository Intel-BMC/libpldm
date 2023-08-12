#include <string.h>

#include <array>
#include <cstring>
#include <vector>
#include <unistd.h>

#include "../base.h"
#include "../platform.h"
#include "../utils.h"
#include "../socket_connect.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::ElementsAreArray;

constexpr auto hdrSize = sizeof(pldm_msg_hdr);
/*
class SocketEnvironment : public ::testing::Environment {
    public:
        ~SocketEnvironment() override {}

        void SetUp() override {
            ASSERT_EQ(initialize_socket_connection(), 0);
        }

        void TearDown() override {
            ASSERT_EQ(close_socket_connection(), 0);
        }
};*/

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

    auto send = socket_send_pldm_message(requestMsg.data(), requestMsg.size());
    EXPECT_EQ(send, 0);
   
 

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
    
    auto send = socket_send_pldm_message(requestMsg.data(), requestMsg.size());
    EXPECT_EQ(send, 0);

    
    
}

TEST(MessagingControlRequest, testSetTID) {
    uint8_t tid = 0x24;
    std::array<uint8_t, hdrSize + sizeof(pldm_set_tid_req)> requestMsg{};
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_set_tid_req(0, tid, request);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(0, memcmp(request->payload, &tid, sizeof(tid)));

    auto send = socket_send_pldm_message(requestMsg.data(), requestMsg.size());
    EXPECT_EQ(send, 0);

    
    

}

TEST(PlatformMonitoringControl, testSetStateEffecterStates) {
    uint16_t effecterId = 0x0A;
    uint8_t compEffecterCnt = 0x2;
    std::array<set_effecter_state_field, 8> stateField{};
    stateField[0] = {PLDM_REQUEST_SET, 2};
    stateField[1] = {PLDM_REQUEST_SET, 3};

    std::array<uint8_t, hdrSize + PLDM_SET_STATE_EFFECTER_STATES_REQ_BYTES> requestMsg{};
    auto request = reinterpret_cast<pldm_msg*>(requestMsg.data());

    auto rc = encode_set_state_effecter_states_req(0, effecterId, compEffecterCnt, stateField.data(), request);
    EXPECT_EQ(rc, PLDM_SUCCESS);
    EXPECT_EQ(effecterId, request->payload[0]);
    EXPECT_EQ(compEffecterCnt, request->payload[sizeof(effecterId)]);
    EXPECT_EQ(stateField[0].set_request,
              request->payload[sizeof(effecterId) + sizeof(compEffecterCnt)]);
    EXPECT_EQ(stateField[0].effecter_state,
              request->payload[sizeof(effecterId) + sizeof(compEffecterCnt) +
                               sizeof(stateField[0].set_request)]);
    EXPECT_EQ(stateField[1].set_request,
              request->payload[sizeof(effecterId) + sizeof(compEffecterCnt) +
                               sizeof(stateField[0])]);
    EXPECT_EQ(stateField[1].effecter_state,
              request->payload[sizeof(effecterId) + sizeof(compEffecterCnt) +
                               sizeof(stateField[0]) +
                               sizeof(stateField[1].set_request)]);

    auto send = socket_send_pldm_message(requestMsg.data(), requestMsg.size());
    EXPECT_EQ(send, 0);
    
  
}



int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::AddGlobalTestEnvironment(new SocketEnvironment);
    return RUN_ALL_TESTS();
}