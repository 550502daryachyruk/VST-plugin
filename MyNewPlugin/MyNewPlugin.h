#ifndef __MYNEWPLUGIN__
#define __MYNEWPLUGIN__

#include "IPlug_include_in_plug_hdr.h"

class MyNewPlugin : public IPlug
{
public:
  MyNewPlugin(IPlugInstanceInfo instanceInfo);
  ~MyNewPlugin();

  void Reset();
  void OnParamChange(int paramIdx);
  void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);

private:
  double mGain;
};

#endif
