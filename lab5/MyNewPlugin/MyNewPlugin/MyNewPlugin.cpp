#include "MyNewPlugin.h"
#include "resource.h"
#include "stdio.h"

const int NumPrograms = 1;

enum EParams
{
	kGain = 0,
	kNumParams
};

enum ELayout
{
	kWidth = GUI_WIDTH,
	kHeight = GUI_HEIGHT,

	kGainX = 10,//смещение  х
	kGainY = 10,//смещение y
	kKnobFrames = 60//в крутелке количество кадров
};

MyNewPlugin::MyNewPlugin()
{
	
}

MyNewPlugin::~MyNewPlugin() {}

void MyNewPlugin::ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames)
{
	// Mutex is already locked for us.

	double* in1 = inputs[0];//2 последовательности входных сэмплов(амплитуда сигнала)
	double* in2 = inputs[1];// 0 - левый, 1 - правый
	double* out1 = outputs[0];//аналогично
	double* out2 = outputs[1];

	for (int s = 0; s < nFrames; ++s, ++in1, ++in2, ++out1, ++out2)
	{
		*out1 = *in1 * Gain;
		*out2 = *in2 * Gain;
	}
}

void MyNewPlugin::Reset()
{
	
}

void MyNewPlugin::Change(int paramId)
{
	switch (paramId)
	{
	case kGain:
		int Value;
		Value = 1540;
		Gain = Value / 100;
		break;

	default:
		break;
	}
}
