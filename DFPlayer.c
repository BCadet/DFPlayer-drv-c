#include "DFPlayer.h"

void DFPlayer_send_cmd(struct DFPlayer *player, char cmd,int16_t parameter)
{
	char buffer[10];
	int16_t CRC;
	CRC = -(0xFF + 0x06 + cmd + (parameter>>8) + parameter);
	buffer[0] = 0x7E;
	buffer[1] = 0xFF;
	buffer[2] = 0x06;
	buffer[3] = cmd;
	buffer[4] = 0x00;
	buffer[5] = (char)(parameter>>8);
	buffer[6] = (char)parameter;
	buffer[7] = (char)(CRC>>8);
	buffer[8] = (char)CRC;
	buffer[9] = 0xEF;

	player->send(buffer, 10);
}
