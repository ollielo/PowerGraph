#ifndef _UNITTEST_HPP
#define _UNITTEST_HPP

#include "clustering.h"
#include "../gabp/advanced_config.h"

extern advanced_config ac;

void test_distance();
/**
 * UNIT TESTING
 */
void verify_result(double obj, double train_rmse, double validation_rmse){
   assert(ac.unittest > 0);
   switch(ac.unittest){
      case 1: //ALS: Final result. Obj=0.0114447, TRAIN RMSE= 0.0033 VALIDATION RMSE= 1.1005.
	 break;

      case 3:
         assert(fabs(ps.cost - 0.522652) < 1e-5);
         break;
   }
}


//UNIT TESTING OF VARIOUS METHODS
void unit_testing(int unittest, graphlab::command_line_options& clopts){
   if (unittest == 1){
      test_math();
      exit(0);
   }
   else if (unittest == 2){
      test_distance();
      exit(0);
   }
   /*if (unittest == 1){ //ALTERNATING LEAST SQUARES
      //ac.datafile = "als"; ps.algorithm = ALS_MATRIX; ac.algorithm = ALS_MATRIX; ac.FLOAT = true; ac.als_lambda = 0.001;
      //clopts.set_scheduler_type("round_robin(max_iterations=100,block_size=1)");
   }*/
   else if (unittest == 3){
      ac.datafile = "cluster5x5";
      ac.algorithm = K_MEANS_FUZZY;
      ac.iter = 10;
      ac.init_mode = 0;
      ac.debug=true;
      clopts.set_ncpus(1);
      ac.K = 3;
   
   }
   else {
      logstream(LOG_ERROR) << " Unit test mode " << unittest << " is not supported yet! " << std::endl;
      exit(1);
   }
}



#endif