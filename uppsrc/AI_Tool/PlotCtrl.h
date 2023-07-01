#ifndef _AI_Tool_PlotCtrl_h_
#define _AI_Tool_PlotCtrl_h_


class Plotter : public Ctrl {
	int mode = 0;
	bool whole_song = false;
	int focused_type = 0;
	String part_key;
	PartScore* part = 0;
	PatternScore* pattern = 0;
	
	Vector<Vector<int>> values;
	Vector<Point> polyline;
	Vector<bool> draw_group;
	Vector<int> vert_lines;
	
public:
	Plotter();
	
	void SetWholeSong(PatternScore& p) {whole_song = true; pattern = &p; Refresh();}
	void SetPart(String key, PartScore& p) {whole_song = false; part_key = key; part = &p; Refresh();}
	void Paint(Draw& d) override;
	
	
	void LeftDown(Point p, dword keyflags) override;
	void MouseWheel(Point p, int zdelta, dword keyflags) override;

};


class PlotCtrl : public Ctrl {
	Plotter plotter;
	DropList choices;
	
	
public:
	typedef PlotCtrl CLASSNAME;
	PlotCtrl();
	
	
};


#endif
