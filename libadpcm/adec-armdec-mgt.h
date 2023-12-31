/*
 * Copyright (C) 2018 Amlogic Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef ADEC_ARMDEC_MGT_H
#define ADEC_ARMDEC_MGT_H


#include <stdlib.h>
#include<stdio.h>
#include <string.h>

//#define AUDIO_ARC_DECODER 0
//#define AUDIO_ARM_DECODER 1
//#define AUDIO_FFMPEG_DECODER 2

#define DEFAULT_PCM_BUFFER_SIZE 192000*2//default out buffer size

//#define AUDIO_EXTRA_DATA_SIZE   (4096)
typedef struct _audio_info {
    int bitrate;
    int samplerate;
    int channels;
    int file_profile;
    unsigned int error_num; // decode error frames
    unsigned int drop_num; // drop frames
    unsigned int decode_num; //decode success frames
} AudioInfo;

/* audio decoder operation*/
typedef struct audio_decoder_operations audio_decoder_operations_t;
struct audio_decoder_operations {
    const char * name;
    int nAudioDecoderType;
    int nInBufSize;
    int nOutBufSize;
    int (*init)(audio_decoder_operations_t *);
    int (*decode)(audio_decoder_operations_t *, char *outbuf, int *outlen, char *inbuf, int inlen);
    int (*release)(audio_decoder_operations_t *);
    int (*getinfo)(audio_decoder_operations_t *, AudioInfo *pAudioInfo);
    void * priv_data;//point to audec
    void * priv_dec_data;//decoder private data
    void *pdecoder; // decoder instance
    int channels;
    unsigned long pts;
    int samplerate;
    int bps;
    int extradata_size;      ///< extra data size
    char extradata[4096];
    int NchOriginal;
    int lfepresent;
    unsigned int block_size;
};

enum AVSampleFormat {
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8,          ///< unsigned 8 bits
    AV_SAMPLE_FMT_S16,         ///< signed 16 bits
    AV_SAMPLE_FMT_S32,         ///< signed 32 bits
    AV_SAMPLE_FMT_FLT,         ///< float
    AV_SAMPLE_FMT_DBL,         ///< double
    AV_SAMPLE_FMT_NB           ///< Number of sample formats. DO NOT USE if linking dynamically
};

#endif
