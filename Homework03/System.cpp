#include "System.h"
System::System( sc_module_name n, string input_bmp, string output_bmp ): sc_module( n ), 
	tb("tb"), gaussian_filter("gaussian_filter"), clk("clk", CLOCK_PERIOD, SC_NS), rst("rst"), _output_bmp(output_bmp)
{
	tb.i_clk(clk);
	tb.o_rst(rst);
	gaussian_filter.i_clk(clk);
	gaussian_filter.i_rst(rst);

	for(int i = 0; i < 9; i++){
		tb.o_rgb[i](rgb[i]);
	}
	tb.i_result(result);

	for(int i = 0; i < 9; i++){
		gaussian_filter.i_rgb[i](rgb[i]);
	}
	gaussian_filter.o_result(result);

  tb.read_bmp(input_bmp);
}

System::~System() {
  tb.write_bmp(_output_bmp);
}
