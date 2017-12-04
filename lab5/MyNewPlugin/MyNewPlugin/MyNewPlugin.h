class MyNewPlugin 
{
public:
	MyNewPlugin();
	~MyNewPlugin();

	void Reset();
	void Change(int paramId);
	void ProcessDoubleReplacing(double** inputs, double** outputs, int Frames);

private:
	double Gain;
};

