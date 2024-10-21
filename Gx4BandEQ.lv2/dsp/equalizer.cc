// generated from file './/equalizer.dsp' by dsp2cc:
// Code generated with Faust 0.9.90 (http://faust.grame.fr)


namespace equalizer {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec1[2];
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec3[2];
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT	*fslider3_;
	double 	fRec4[2];
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT	*fslider4_;
	double 	fRec6[2];
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT	*fslider5_;
	double 	fRec7[2];
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT	*fslider6_;
	double 	fRec9[2];
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fConst44;
	double 	fConst45;
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT	*fslider7_;
	double 	fRec10[2];
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fRec11[3];
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fRec8[3];
	double 	fConst57;
	double 	fConst58;
	double 	fConst59;
	double 	fRec5[3];
	double 	fConst60;
	double 	fConst61;
	double 	fConst62;
	double 	fRec2[3];
	double 	fConst63;
	double 	fConst64;
	double 	fConst65;

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "equalizer";
	name = N_("4BandEq");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<3; i++) fRec11[i] = 0;
	for (int i=0; i<3; i++) fRec8[i] = 0;
	for (int i=0; i<3; i++) fRec5[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(1.92e+05, max(1.0, (double)fSamplingFreq)));
	fConst1 = (1.2932173558506e-09 * fConst0);
	fConst2 = (8.42157694614872e-06 + fConst1);
	fConst3 = (2.75152628904382e-10 * fConst0);
	fConst4 = (fConst3 - 5.01689092029113e-06);
	fConst5 = (1.7918248821593e-06 + fConst3);
	fConst6 = (1.29319149202076e-09 * fConst0);
	fConst7 = (1.61269271552793e-06 - fConst6);
	fConst8 = (2.75147125961863e-10 * fConst0);
	fConst9 = (8.60050484882881e-06 - fConst8);
	fConst10 = (fConst8 - 1.79178904637838e-06);
	fConst11 = (fConst1 - 8.42157694614872e-06);
	fConst12 = (5.01689092029113e-06 + fConst3);
	fConst13 = (1.7918248821593e-06 - fConst3);
	fConst14 = faustpower<2>(fConst0);
	fConst15 = (1.38181404635165e-09 * fConst0);
	fConst16 = (5.07609303633698e-06 + fConst15);
	fConst17 = (2.94002988585458e-10 * fConst0);
	fConst18 = (fConst17 - 3.02392357481196e-06);
	fConst19 = (1.08001979496531e-06 + fConst17);
	fConst20 = (1.38178641062344e-09 * fConst0);
	fConst21 = (9.72048146729374e-07 - fConst20);
	fConst22 = (2.93997108643285e-10 * fConst0);
	fConst23 = (5.18394156477869e-06 - fConst22);
	fConst24 = (fConst22 - 1.07999819500141e-06);
	fConst25 = (fConst15 - 5.07609303633698e-06);
	fConst26 = (3.02392357481196e-06 + fConst17);
	fConst27 = (1.08001979496531e-06 - fConst17);
	fConst28 = (1.45798052941639e-09 * fConst0);
	fConst29 = (2.08879732008079e-06 + fConst28);
	fConst30 = (3.10208623280084e-10 * fConst0);
	fConst31 = (fConst30 - 1.24433563647887e-06);
	fConst32 = (4.44424961719318e-07 + fConst30);
	fConst33 = (1.45795137038899e-09 * fConst0);
	fConst34 = (3.99994946771703e-07 - fConst33);
	fConst35 = (3.10202419231699e-10 * fConst0);
	fConst36 = (2.13317667159604e-06 - fConst35);
	fConst37 = (fConst35 - 4.4441607339785e-07);
	fConst38 = (fConst28 - 2.08879732008079e-06);
	fConst39 = (1.24433563647887e-06 + fConst30);
	fConst40 = (4.44424961719318e-07 - fConst30);
	fConst41 = (1.49858429037152e-09 * fConst0);
	fConst42 = (4.56801893059661e-07 + fConst41);
	fConst43 = (3.18847721355644e-10 * fConst0);
	fConst44 = (fConst43 - 2.72125432602126e-07);
	fConst45 = (9.71918921403535e-08 + fConst43);
	fConst46 = (1.49855431928514e-09 * fConst0);
	fConst47 = (8.74754324620374e-08 - fConst46);
	fConst48 = (3.18841344528753e-10 * fConst0);
	fConst49 = (4.66507273083866e-07 - fConst48);
	fConst50 = (fConst48 - 9.71899483413867e-08);
	fConst51 = (fConst41 - 4.56801893059661e-07);
	fConst52 = (2.72125432602126e-07 + fConst43);
	fConst53 = (9.71918921403535e-08 - fConst43);
	fConst54 = (8.74754324620374e-08 + fConst46);
	fConst55 = (4.66507273083866e-07 + fConst48);
	fConst56 = (9.71899483413867e-08 + fConst48);
	fConst57 = (3.99994946771703e-07 + fConst33);
	fConst58 = (2.13317667159604e-06 + fConst35);
	fConst59 = (4.4441607339785e-07 + fConst35);
	fConst60 = (9.72048146729374e-07 + fConst20);
	fConst61 = (5.18394156477869e-06 + fConst22);
	fConst62 = (1.07999819500141e-06 + fConst22);
	fConst63 = (1.61269271552793e-06 + fConst6);
	fConst64 = (8.60050484882881e-06 + fConst8);
	fConst65 = (1.79178904637838e-06 + fConst8);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
#define fslider3 (*fslider3_)
#define fslider4 (*fslider4_)
#define fslider5 (*fslider5_)
#define fslider6 (*fslider6_)
#define fslider7 (*fslider7_)
	double 	fSlow0 = (0.007000000000000006 * double(fslider0));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	double 	fSlow2 = (0.007000000000000006 * double(fslider2));
	double 	fSlow3 = (0.007000000000000006 * double(fslider3));
	double 	fSlow4 = (0.007000000000000006 * double(fslider4));
	double 	fSlow5 = (0.007000000000000006 * double(fslider5));
	double 	fSlow6 = (0.007000000000000006 * double(fslider6));
	double 	fSlow7 = (0.007000000000000006 * double(fslider7));
	for (int i=0; i<count; i++) {
		fRec0[0] = (fSlow0 + (0.993 * fRec0[1]));
		double fTemp0 = (fConst0 * (((1.17971787847992e-09 * fRec0[0]) - 1.23516461876848e-09) - 1.23516461876848e-09));
		double fTemp1 = (2.51003803931899e-10 * fRec0[0]);
		double fTemp2 = (fConst0 * ((fTemp1 - 2.62800982716698e-10) - 2.62800982716698e-10));
		double fTemp3 = (fConst0 * (2.62800982716698e-10 + (2.62800982716698e-10 + (0 - fTemp1))));
		fRec1[0] = (fSlow1 + (0.993 * fRec1[1]));
		double fTemp4 = (0.00609358408305745 + ((fRec1[0] * (0.00129650725171435 + ((fRec1[0] * ((fConst0 * ((fRec0[0] * (fTemp3 + 1.711389572262945e-06)) - fConst5)) - 0.00129650725171435)) + (fConst0 * (fConst4 + (fRec0[0] * (fTemp2 + 4.791681872293345e-06))))))) + (fConst0 * (fConst2 + (fRec0[0] * (fTemp0 - 8.04353098963584e-06))))));
		double fTemp5 = (fConst0 * (1.23513991597016e-09 + (1.23513991597016e-09 + (0 - (1.17969428459423e-09 * fRec0[0])))));
		double fTemp6 = (2.50998783956219e-10 * fRec0[0]);
		double fTemp7 = (fConst0 * (2.62795726802162e-10 + (2.62795726802162e-10 + (0 - fTemp6))));
		double fTemp8 = (fConst0 * ((fTemp6 - 2.62795726802162e-10) - 2.62795726802162e-10));
		double fTemp9 = (5.02007607863797e-10 * fRec0[0]);
		fRec3[0] = (fSlow2 + (0.993 * fRec3[1]));
		double fTemp10 = (fConst0 * (((1.2605388628917e-09 * fRec3[0]) - 1.31978418944761e-09) - 1.31978418944761e-09));
		double fTemp11 = (2.68199758062065e-10 * fRec3[0]);
		double fTemp12 = (fConst0 * ((fTemp11 - 2.80805146690982e-10) - 2.80805146690982e-10));
		double fTemp13 = (fConst0 * (2.80805146690982e-10 + (2.80805146690982e-10 + (0 - fTemp11))));
		fRec4[0] = (fSlow3 + (0.993 * fRec4[1]));
		double fTemp14 = (0.00207189162210997 + ((fRec4[0] * (0.000440828004704248 + ((fRec4[0] * ((fConst0 * ((fRec3[0] * (fTemp13 + 1.031537531007942e-06)) - fConst19)) - 0.000440828004704248)) + (fConst0 * (fConst18 + (fRec3[0] * (fTemp12 + 2.888179154548196e-06))))))) + (fConst0 * (fConst16 + (fRec3[0] * (fTemp10 - 4.84822639573732e-06))))));
		double fTemp15 = (fConst0 * (1.31975779429173e-09 + (1.31975779429173e-09 + (0 - (1.26051365261865e-09 * fRec3[0])))));
		double fTemp16 = (2.68194394174181e-10 * fRec3[0]);
		double fTemp17 = (fConst0 * (2.80799530700368e-10 + (2.80799530700368e-10 + (0 - fTemp16))));
		double fTemp18 = (fConst0 * ((fTemp16 - 2.80799530700368e-10) - 2.80799530700368e-10));
		double fTemp19 = (5.36399516124129e-10 * fRec3[0]);
		fRec6[0] = (fSlow4 + (0.993 * fRec6[1]));
		double fTemp20 = (fConst0 * (((1.33002057948475e-09 * fRec6[0]) - 1.39253154672053e-09) - 1.39253154672053e-09));
		double fTemp21 = (2.82983102018031e-10 * fRec6[0]);
		double fTemp22 = (fConst0 * ((fTemp21 - 2.96283307812879e-10) - 2.96283307812879e-10));
		double fTemp23 = (fConst0 * (2.96283307812879e-10 + (2.96283307812879e-10 + (0 - fTemp21))));
		fRec7[0] = (fSlow5 + (0.993 * fRec7[1]));
		double fTemp24 = (0.000332505144871187 + ((fRec7[0] * (7.07457755045078e-05 + ((fRec7[0] * ((fConst0 * ((fRec6[0] * (fTemp23 + 4.24474653027047e-07)) - fConst32)) - 7.07457755045078e-05)) + (fConst0 * (fConst31 + (fRec6[0] * (fTemp22 + 1.188477207716214e-06))))))) + (fConst0 * (fConst29 + (fRec6[0] * (fTemp20 - 1.995030869227123e-06))))));
		double fTemp25 = (fConst0 * (1.3925036966466e-09 + (1.3925036966466e-09 + (0 - (1.32999397960515e-09 * fRec6[0])))));
		double fTemp26 = (2.82977442469182e-10 * fRec6[0]);
		double fTemp27 = (fConst0 * (2.96277382265233e-10 + (2.96277382265233e-10 + (0 - fTemp26))));
		double fTemp28 = (fConst0 * ((fTemp26 - 2.96277382265233e-10) - 2.96277382265233e-10));
		double fTemp29 = (5.65966204036062e-10 * fRec6[0]);
		fRec9[0] = (fSlow6 + (0.993 * fRec9[1]));
		double fTemp30 = (fConst0 * (((1.36706074331768e-09 * fRec9[0]) - 1.43131259825361e-09) - 1.43131259825361e-09));
		double fTemp31 = (2.90863987939931e-10 * fRec9[0]);
		double fTemp32 = (fConst0 * ((fTemp31 - 3.04534595373108e-10) - 3.04534595373108e-10));
		double fTemp33 = (fConst0 * (3.04534595373108e-10 + (3.04534595373108e-10 + (0 - fTemp31))));
		fRec10[0] = (fSlow7 + (0.993 * fRec10[1]));
		double fTemp34 = (1.54714887202091e-05 + ((fRec10[0] * (3.29180611068278e-06 + ((fRec10[0] * ((fConst0 * ((fRec9[0] * (fTemp33 + 9.282893232125459e-08)) - fConst45)) - 3.29180611068278e-06)) + (fConst0 * (fConst44 + (fRec9[0] * (fTemp32 + 2.599096777479718e-07))))))) + (fConst0 * (fConst42 + (fRec9[0] * (fTemp30 - 4.36295981909896e-07))))));
		double fTemp35 = (fConst0 * (1.43128397257415e-09 + (1.43128397257415e-09 + (0 - (1.36703340264962e-09 * fRec9[0])))));
		double fTemp36 = (2.90858170776515e-10 * fRec9[0]);
		double fTemp37 = (fConst0 * (3.04528504803012e-10 + (3.04528504803012e-10 + (0 - fTemp36))));
		double fTemp38 = (fConst0 * ((fTemp36 - 3.04528504803012e-10) - 3.04528504803012e-10));
		double fTemp39 = (5.81727975879862e-10 * fRec9[0]);
		fRec11[0] = ((double)input0[i] - (((fRec11[1] * (3.09429774404182e-05 + ((fRec10[0] * (6.58361222136557e-06 + ((fRec10[0] * ((fConst14 * (6.37695442711287e-10 + (fRec9[0] * ((fTemp39 - 6.09069190746215e-10) - 6.09069190746215e-10)))) - 6.58361222136557e-06)) + (fConst14 * ((fRec9[0] * (1.21813838149243e-09 - fTemp39)) - 6.37695442711287e-10))))) + (fConst14 * ((fRec9[0] * (5.72525039301442e-09 - (2.73412148663535e-09 * fRec9[0]))) - 2.99716858074305e-09))))) + (fRec11[2] * (1.54714887202091e-05 + ((fRec10[0] * (3.29180611068278e-06 + ((fRec10[0] * ((fConst0 * (fConst53 + (fRec9[0] * (fTemp33 - 9.282893232125459e-08)))) - 3.29180611068278e-06)) + (fConst0 * (fConst52 + (fRec9[0] * (fTemp32 - 2.599096777479718e-07))))))) + (fConst0 * (fConst51 + (fRec9[0] * (4.36295981909896e-07 + fTemp30)))))))) / fTemp34));
		double fTemp40 = (5.81716341553031e-10 * fRec9[0]);
		fRec8[0] = (((((fRec11[0] * (((fRec10[0] * (((fRec10[0] * (3.29174027587727e-06 + (fConst0 * (fConst56 + (fRec9[0] * (fTemp38 - 9.28270757797389e-08)))))) + (fConst0 * ((fRec9[0] * (4.455656858489653e-07 + fTemp37)) - fConst55))) - 3.29174027587727e-06)) + (fConst0 * ((fRec9[0] * (8.35486460955471e-08 + fTemp35)) - fConst54))) - 1.54711792966232e-05)) + (fRec11[1] * (((fRec10[0] * (((fRec10[0] * (6.58348055175453e-06 + (fConst14 * ((fRec9[0] * (1.218114019212046e-09 - fTemp40)) - 6.37682689057506e-10)))) + (fConst14 * (6.37682689057506e-10 + (fRec9[0] * (fTemp40 - 1.218114019212046e-09))))) - 6.58348055175453e-06)) + (fConst14 * (2.99710863857028e-09 + (fRec9[0] * ((2.73406680529924e-09 * fRec9[0]) - 5.72513589029662e-09))))) - 3.09423585932463e-05))) + (fRec11[2] * (((fRec10[0] * (((fRec10[0] * (3.29174027587727e-06 + (fConst0 * (fConst50 + (fRec9[0] * (fTemp38 + 9.28270757797389e-08)))))) + (fConst0 * (fConst49 + (fRec9[0] * (fTemp37 - 4.455656858489653e-07))))) - 3.29174027587727e-06)) + (fConst0 * (fConst47 + (fRec9[0] * (fTemp35 - 8.35486460955471e-08))))) - 1.54711792966232e-05))) / fTemp34) - (((fRec8[1] * (0.000665010289742373 + ((fRec7[0] * (0.000141491551009016 + ((fRec7[0] * ((fConst14 * (6.20417246560168e-10 + (fRec6[0] * ((fTemp29 - 5.92566615625757e-10) - 5.92566615625757e-10)))) - 0.000141491551009016)) + (fConst14 * ((fRec6[0] * (1.185133231251514e-09 - fTemp29)) - 6.20417246560168e-10))))) + (fConst14 * ((fRec6[0] * (5.57012618688212e-09 - (2.66004115896949e-09 * fRec6[0]))) - 2.91596105883279e-09))))) + (fRec8[2] * (0.000332505144871187 + ((fRec7[0] * (7.07457755045078e-05 + ((fRec7[0] * ((fConst0 * (fConst40 + (fRec6[0] * (fTemp23 - 4.24474653027047e-07)))) - 7.07457755045078e-05)) + (fConst0 * (fConst39 + (fRec6[0] * (fTemp22 - 1.188477207716214e-06))))))) + (fConst0 * (fConst38 + (fRec6[0] * (1.995030869227123e-06 + fTemp20)))))))) / fTemp24));
		double fTemp41 = (5.65954884938364e-10 * fRec6[0]);
		fRec5[0] = (((((fRec8[0] * (((fRec7[0] * (((fRec7[0] * (7.07443606172955e-05 + (fConst0 * (fConst59 + (fRec6[0] * (fTemp28 - 4.24466163703773e-07)))))) + (fConst0 * ((fRec6[0] * (2.037418024447031e-06 + fTemp27)) - fConst58))) - 7.07443606172955e-05)) + (fConst0 * ((fRec6[0] * (3.8203910866447203e-07 + fTemp25)) - fConst57))) - 0.000332498494901289)) + (fRec8[1] * (((fRec7[0] * (((fRec7[0] * (0.000141488721234591 + (fConst14 * ((fRec6[0] * (1.185109529060934e-09 - fTemp41)) - 6.20404838463398e-10)))) + (fConst14 * (6.20404838463398e-10 + (fRec6[0] * (fTemp41 - 1.185109529060934e-09))))) - 0.000141488721234591)) + (fConst14 * (2.91590274077797e-09 + (fRec6[0] * ((2.65998795921031e-09 * fRec6[0]) - 5.57001478658638e-09))))) - 0.000664996989802577))) + (fRec8[2] * (((fRec7[0] * (((fRec7[0] * (7.07443606172955e-05 + (fConst0 * (fConst37 + (fRec6[0] * (fTemp28 + 4.24466163703773e-07)))))) + (fConst0 * (fConst36 + (fRec6[0] * (fTemp27 - 2.037418024447031e-06))))) - 7.07443606172955e-05)) + (fConst0 * (fConst34 + (fRec6[0] * (fTemp25 - 3.8203910866447203e-07))))) - 0.000332498494901289))) / fTemp24) - (((fRec5[1] * (0.00414378324421993 + ((fRec4[0] * (0.000881656009408497 + ((fRec4[0] * ((fConst14 * (5.88005977170916e-10 + (fRec3[0] * ((fTemp19 - 5.61610293381963e-10) - 5.61610293381963e-10)))) - 0.000881656009408497)) + (fConst14 * ((fRec3[0] * (1.123220586763926e-09 - fTemp19)) - 5.88005977170916e-10))))) + (fConst14 * ((fRec3[0] * (5.27913675779046e-09 - (2.52107772578341e-09 * fRec3[0]))) - 2.7636280927033e-09))))) + (fRec5[2] * (0.00207189162210997 + ((fRec4[0] * (0.000440828004704248 + ((fRec4[0] * ((fConst0 * (fConst27 + (fRec3[0] * (fTemp13 - 1.031537531007942e-06)))) - 0.000440828004704248)) + (fConst0 * (fConst26 + (fRec3[0] * (fTemp12 - 2.888179154548196e-06))))))) + (fConst0 * (fConst25 + (fRec3[0] * (4.84822639573732e-06 + fTemp10)))))))) / fTemp14));
		double fTemp42 = (5.36388788348363e-10 * fRec3[0]);
		fRec2[0] = (((((fRec5[0] * (((fRec4[0] * (((fRec4[0] * (0.000440819188320482 + (fConst0 * (fConst62 + (fRec3[0] * (fTemp18 - 1.031516900669928e-06)))))) + (fConst0 * ((fRec3[0] * (4.951233586226066e-06 + fTemp17)) - fConst61))) - 0.000440819188320482)) + (fConst0 * ((fRec3[0] * (9.284127475925289e-07 + fTemp15)) - fConst60))) - 0.00207185018510627)) + (fRec5[1] * (((fRec4[0] * (((fRec4[0] * (0.000881638376640964 + (fConst14 * ((fRec3[0] * (1.12319812280147e-09 - fTemp42)) - 5.8799421728657e-10)))) + (fConst14 * (5.8799421728657e-10 + (fRec3[0] * (fTemp42 - 1.12319812280147e-09))))) - 0.000881638376640964)) + (fConst14 * (2.76357282124688e-09 + (fRec3[0] * ((2.5210273052373e-09 * fRec3[0]) - 5.27903117716692e-09))))) - 0.00414370037021253))) + (fRec5[2] * (((fRec4[0] * (((fRec4[0] * (0.000440819188320482 + (fConst0 * (fConst24 + (fRec3[0] * (fTemp18 + 1.031516900669928e-06)))))) + (fConst0 * (fConst23 + (fRec3[0] * (fTemp17 - 4.951233586226066e-06))))) - 0.000440819188320482)) + (fConst0 * (fConst21 + (fRec3[0] * (fTemp15 - 9.284127475925289e-07))))) - 0.00207185018510627))) / fTemp14) - (((fRec2[1] * (0.0121871681661149 + ((fRec1[0] * (0.0025930145034287 + ((fRec1[0] * ((fConst14 * (5.50305257808765e-10 + (fRec0[0] * ((fTemp9 - 5.25601965433395e-10) - 5.25601965433395e-10)))) - 0.0025930145034287)) + (fConst14 * ((fRec0[0] * (1.05120393086679e-09 - fTemp9)) - 5.50305257808765e-10))))) + (fConst14 * ((fRec0[0] * (4.94065847507392e-09 - (2.35943575695985e-09 * fRec0[0]))) - 2.5864347117012e-09))))) + (fRec2[2] * (0.00609358408305745 + ((fRec1[0] * (0.00129650725171435 + ((fRec1[0] * ((fConst0 * (fConst13 + (fRec0[0] * (fTemp3 - 1.711389572262945e-06)))) - 0.00129650725171435)) + (fConst0 * (fConst12 + (fRec0[0] * (fTemp2 - 4.791681872293345e-06))))))) + (fConst0 * (fConst11 + (fRec0[0] * (8.04353098963584e-06 + fTemp0)))))))) / fTemp4));
		double fTemp43 = (5.01997567912439e-10 * fRec0[0]);
		output0[i] = (FAUSTFLOAT)((((fRec2[0] * (((fRec1[0] * (((fRec1[0] * (0.00129648132208791 + (fConst0 * (fConst65 + (fRec0[0] * (fTemp8 - 1.711355345156041e-06)))))) + (fConst0 * ((fRec0[0] * (8.21442678971233e-06 + fTemp7)) - fConst64))) - 0.00129648132208791)) + (fConst0 * ((fRec0[0] * (1.54029867767711e-06 + fTemp5)) - fConst63))) - 0.00609346221381318)) + (fRec2[1] * (((fRec1[0] * (((fRec1[0] * (0.00259296264417582 + (fConst14 * ((fRec0[0] * (1.051182907208646e-09 - fTemp43)) - 5.50294251923727e-10)))) + (fConst14 * (5.50294251923727e-10 + (fRec0[0] * (fTemp43 - 1.051182907208646e-09))))) - 0.00259296264417582)) + (fConst14 * (2.58638298404152e-09 + (fRec0[0] * ((2.35938856918846e-09 * fRec0[0]) - 4.94055966388064e-09))))) - 0.0121869244276264))) + (fRec2[2] * (((fRec1[0] * (((fRec1[0] * (0.00129648132208791 + (fConst0 * (fConst10 + (fRec0[0] * (fTemp8 + 1.711355345156041e-06)))))) + (fConst0 * (fConst9 + (fRec0[0] * (fTemp7 - 8.21442678971233e-06))))) - 0.00129648132208791)) + (fConst0 * (fConst7 + (fRec0[0] * (fTemp5 - 1.54029867767711e-06))))) - 0.00609346221381318))) / fTemp4);
		// post processing
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
		fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
		fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
		fRec10[1] = fRec10[0];
		fRec9[1] = fRec9[0];
		fRec7[1] = fRec7[0];
		fRec6[1] = fRec6[0];
		fRec4[1] = fRec4[0];
		fRec3[1] = fRec3[0];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
#undef fslider3
#undef fslider4
#undef fslider5
#undef fslider6
#undef fslider7
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case FREQ1: 
		fslider4_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case FREQ2: 
		fslider6_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case FREQ3: 
		fslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case FREQ4: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case BOOST1: 
		fslider7_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case BOOST2: 
		fslider5_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case BOOST3: 
		fslider3_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case BOOST4: 
		fslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   150-3KHZ, 
   35-680HZ, 
   5KHZ, 
   750-15KHZ, 
   BOOST1, 
   BOOST2, 
   BOOST3, 
   BOOST4, 
} PortIndex;
*/

} // end namespace equalizer
