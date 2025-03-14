#ifndef CONSTANTS_CRACK
#define CONSTANTS_CRACK

enum CrackStatus
{
    SuccCrack = 0,
    FailCrack = 1,
};

//------------Constants---------------
const unsigned int Width        = 506;
const unsigned int Height       = 284;

const unsigned int PngColomns   = 6;
const unsigned int PngStrings   = 14;
const int NumOfFrames           = 81;

const int ShiftFrameBackX = (PngColomns - 1) * Width;
const int ShiftFrameBackY = (PngStrings - 1) * Height;

const int MlsPerFrame = 80000;
//------------------------------------

#endif