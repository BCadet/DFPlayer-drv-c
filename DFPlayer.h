#ifndef DFPLAYER_H
#define DFPLAYER_H

#include <stdint.h>

#define DFPLAYER_CMD_NEXT 0x01
#define DFPLAYER_CMD_PRESVIOUS 0x02
#define DFPLAYER_CMD_TRACK 0x03
#define DFPLAYER_CMD_VOLUME_P 0x04
#define DFPLAYER_CMD_VOLUME_M 0x05
#define DFPLAYER_CMD_VOL_MANU 0x06
#define DFPLAYER_CMD_EQ 0x07
#define DFPLAYER_CMD_MODE 0x08
#define DFPLAYER_CMD_STDBY 0x0A
#define DFPLAYER_CMD_NORMAL 0x0B
#define DFPLAYER_CMD_RESET 0x0C
#define DFPLAYER_CMD_PLAYBACK 0x0D
#define DFPLAYER_CMD_PAUSE 0x0E
#define DFPLAYER_CMD_FOLDER 0x0F
#define DFPLAYER_CMD_VOL_ADJ 0x10
#define DFPLAYER_CMD_REPEAT 0x11

#define DFPLAYER_QRY_PARAM 0x3F
#define DFPLAYER_QRY_ERROR 0x40
#define DFPLAYER_QRY_REPLY 0x41
#define DFPLAYER_QRY_CUR_STAT 0x42
#define DFPLAYER_QRY_CUR_VOL 0x43
#define DFPLAYER_QRY_CUR_EQ 0x44
#define DFPLAYER_QRY_CUR_MODE 0x45
#define DFPLAYER_QRY_CUR_VER 0x46
#define DFPLAYER_QRY_N_TF_FILE 0x47
#define DFPLAYER_QRY_N_USB_FILE 0x48
#define DFPLAYER_QRY_N_FLSH_FILE 0x49
#define DFPLAYER_QRY_KEEP_ON 0x4A
#define DFPLAYER_QRY_TF_TRACK 0x4B
#define DFPLAYER_QRY_USB_TRACK 0x4C
#define DFPLAYER_QRY_FLASH_TRACK 0x4D

#define DFPLAYER_USB_ONLINE                                        \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3F, 0x00, 0x00, 0x01, 0xFF, 0xC0, 0xEF \
    }
#define DFPLAYER_SD_ONLINE                                         \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3F, 0x00, 0x00, 0x02, 0xFF, 0xBF, 0xEF \
    }
#define DFPLAYER_USB_SD_ONLINE                                     \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3F, 0x00, 0x00, 0x03, 0xFF, 0xBE, 0xEF \
    }
#define DFPLAYER_PC_ONLINE                                         \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3F, 0x00, 0x00, 0x04, 0xFF, 0xBD, 0xEF \
    }
#define DFPLAYER_FLASH_ONLINE                                      \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3F, 0x00, 0x00, 0x08, 0xFF, 0xB9, 0xEF \
    }

#define DFPLAYER_USB_PUSH_IN                                       \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3A, 0x00, 0x00, 0x01, 0xFF, 0xC5, 0xEF \
    }
#define DFPLAYER_SD_PUSH_IN                                        \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3A, 0x00, 0x00, 0x02, 0xFF, 0xC4, 0xEF \
    }
#define DFPLAYER_USB_PUSH_OUT                                      \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3B, 0x00, 0x00, 0x01, 0xFF, 0xC4, 0xEF \
    }
#define DFPLAYER_SD_PUSH_OUT                                       \
    {                                                              \
        0x7E, 0xFF, 0x06, 0x3B, 0x00, 0x00, 0x02, 0xFF, 0xC3, 0xEF \
    }

typedef uint8_t (*dfplayer_send_fptr)(uint8_t *data, uint32_t length);

struct DFPlayer {
    dfplayer_send_fptr send;
};

void DFPlayer_send_cmd(struct DFPlayer *player, char cmd,int16_t parameter);

#endif /* DFPLAYER_H */
