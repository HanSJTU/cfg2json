#include<iostream>
#include<stdio.h>
#include<string.h>
#include<typeinfo>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
//#include "/usr/local/include/boost/regex.h"
#include "/usr/local/include/boost/regex.hpp"
#include<stdlib.h>
#include<string>
#include<stdlib.h>
#include<vector>

bool first_layer = false;

void typein_conv(FILE* out,int i_w,int i_h,int i_d, int i_ba, \
int k_w, int k_h, int k_d, int k_s_w, int k_s_h, int k_p_w, int k_p_h){
  if(first_layer==true)  fputs(",\n\t\t\t{",out);
  else {fputs("\n\t\t\t{",out);first_layer=true;}
  fputs("\n\t\t\t\"type\":\"convolution\",\n",out);
  fputs("\t\t\t\"weight_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"weight_offset\":0,\n",out);
  fputs("\t\t\t\"weight_size\":0,\n",out);
  fputs("\t\t\t\"bias_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"bias_offset\":0,\n",out);
  fputs("\t\t\t\"bias_size\":0,\n",out);
  fputs("\t\t\t\"data\":{\n",out);
  fputs("\t\t\t\t\"input_width\":",out);
  char a[20];
  sprintf(a,"%d,",i_w);
  fputs(a,out);
  fputs("\"input_height\":",out);
  sprintf(a,"%d,",i_h);
  fputs(a,out);
  fputs("\"input_depth\":",out);
  sprintf(a,"%d,",i_d);
  fputs(a,out);
  fputs("\"input_batch\":",out);
  sprintf(a,"%d,",i_ba);
  fputs(a,out);
  fputs("\"kernel_width\":",out);
  sprintf(a,"%d,",k_w);
  fputs(a,out);
  fputs("\"kernel_height\":",out);
  sprintf(a,"%d,",k_h);
  fputs(a,out);
  fputs("\"kernel_depth\":",out);
  sprintf(a,"%d,",k_d);
  fputs(a,out);
  fputs("\"kernel_stride_w\":",out);
  sprintf(a,"%d,",k_s_w);
  fputs(a,out);
  fputs("\"kernel_stride_h\":",out);
  sprintf(a,"%d,",k_s_h);
  fputs(a,out);
  fputs("\"k_padding_w\":",out);
  sprintf(a,"%d,",k_p_w);
  fputs(a,out);
  fputs("\"k_padding_h\":",out);
  sprintf(a,"%d\n",k_p_h);
  fputs(a,out);
  fputs("\t\t\t\t}\n\t\t\t}",out);
}

void typein_pool(FILE *out,int i_w,int i_h,int i_d,\
                  int i_b, \
                  int k_w,int k_h, \
                  int k_s_w,int k_s_h, \
                  int k_p_w,int k_p_h, \
                  int p_type){
  if(first_layer==true)  fputs(",\n\t\t\t{",out);
  else {fputs("/n\t\t\t{",out);first_layer=true;}
  fputs("\n\t\t\t\"type\":\"pooling\",\n",out);
  fputs("\t\t\t\"weight_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"weight_offset\":0,\n",out);
  fputs("\t\t\t\"weight_size\":0,\n",out);
  fputs("\t\t\t\"bias_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"bias_offset\":0,\n",out);
  fputs("\t\t\t\"bias_size\":0,\n",out);
  fputs("\t\t\t\"data\":{\n",out);
  fputs("\t\t\t\t\"input_width\":",out);
  char a[20];
  sprintf(a,"%d,",i_w);
  fputs(a,out);
  fputs("\"input_height\":",out);
  sprintf(a,"%d,",i_h);
  fputs(a,out);
  fputs("\"input_depth\":",out);
  sprintf(a,"%d,",i_d);
  fputs(a,out);
  fputs("\"input_batch\":",out);
  sprintf(a,"%d,",i_b);
  fputs(a,out);
  fputs("\"kernel_width\":",out);
  sprintf(a,"%d,",k_w);
  fputs(a,out);
  fputs("\"kernel_height\":",out);
  sprintf(a,"%d,",k_h);
  fputs(a,out);
  fputs("\"kernel_stride_w\":",out);
  sprintf(a,"%d,",k_s_w);
  fputs(a,out);
  fputs("\"kernel_stride_h\":",out);
  sprintf(a,"%d,",k_s_h);
  fputs(a,out);
  fputs("\"k_padding_w\":",out);
  sprintf(a,"%d,",k_p_w);
  fputs(a,out);
  fputs("\"k_padding_h\":",out);
  sprintf(a,"%d,",k_p_h);
  fputs(a,out);
  fputs("\"pool_type\":",out);
  sprintf(a,"%d\n",p_type);
  fputs(a,out);
  fputs("\t\t\t\t}\n\t\t\t}",out);
  }

void typein_route(FILE* out, int i_w, int i_h, int i_d){
  if(first_layer==true)  fputs(",\n\t\t\t{",out);
  else {fputs("/n\t\t\t{",out);first_layer=true;}
  fputs("\n\t\t\t\"type\":\"full_connection\",\n",out);
  fputs("\t\t\t\"weight_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"weight_offset\":0,\n",out);
  fputs("\t\t\t\"weight_size\":0,\n",out);
  fputs("\t\t\t\"bias_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"bias_offset\":0,\n",out);
  fputs("\t\t\t\"bias_size\":0,\n",out);
  fputs("\t\t\t\"data\":{\n",out);
  fputs("\t\t\t\t\"input_width\":",out);
  char a[20];
  sprintf(a,"%d,",i_w);
  fputs(a,out);
  fputs("\"input_height\":",out);
  sprintf(a,"%d,",i_h);
  fputs(a,out);
  fputs("\"input_depth\":",out);
  sprintf(a,"%d,",i_d);
  fputs(a,out);
  
  fputs("\"output_width\":",out);
  sprintf(a,"%d,",i_w);
  fputs(a,out);

  fputs("\"output_height\":",out);
  sprintf(a,"%d,",i_h);
  fputs(a,out);

  fputs("\"output_depth\":",out);
  sprintf(a,"%d\n",i_d);
  fputs(a,out);

  fputs("\t\t\t\t}\n\t\t\t}",out);
}

void typein_region(FILE* out,int i_w,int i_h,int i_d, \
                    int i_b, \
                    int classes, int coords, int num, int softmax){
  if(first_layer==true)  fputs(",\n\t\t\t{",out);
  else {fputs("/n\t\t\t{",out);first_layer=true;}
  fputs("\n\t\t\t\"type\":\"region\",\n",out);
  fputs("\t\t\t\"weight_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"weight_offset\":0,\n",out);
  fputs("\t\t\t\"weight_size\":0,\n",out);
  fputs("\t\t\t\"bias_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"bias_offset\":0,\n",out);
  fputs("\t\t\t\"bias_size\":0,\n",out);
  fputs("\t\t\t\"data\":{\n",out);
  fputs("\t\t\t\t\"input_width\":",out);
  char a[20];
  sprintf(a,"%d,",i_w);
  fputs(a,out);
  fputs("\"input_height\":",out);
  sprintf(a,"%d,",i_h);
  fputs(a,out);
  fputs("\"input_depth\":",out);
  sprintf(a,"%d,",i_d);
  fputs(a,out);
  fputs("\"input_batch\":",out);
  sprintf(a,"%d,",i_b);
  fputs(a,out);
  fputs("\"classes\":",out);
  sprintf(a,"%d,",classes);
  fputs(a,out);
  fputs("\"coords\":",out);
  sprintf(a,"%d,",coords);
  fputs(a,out);
  fputs("\"num\":",out);
  sprintf(a,"%d,",num);
  fputs(a,out);
  fputs("\"softmax\":",out);
  sprintf(a,"%d\n",softmax);
  fputs(a,out);
  fputs("\t\t\t\t}\n\t\t\t}",out);
}

void head_typein(FILE* out, int num_layers){
  fputs("[\n\t{\n\t\t\"test_name\":\"YOLO\",\n",out);
  fputs("\t\t\"prec\":\"PREC_FP32\",\n",out);
  fputs("\t\t\"lib_type\":\"IMPL_LIB_INTERNEL_OPT\",\n",out);
  fputs("\t\t\"eng_type\":\"COMPTUE_ENGINE_GPU\",\n",out);
  fputs("\t\t\"queue_type\":\"CMD_QUEUE_IN_ORDER\",\n",out);
  char a[16];
  sprintf(a,"%d,\n",num_layers);
  fputs("\t\t\"layer_cnt\":",out);
  fputs(a,out);
  fputs("\t\t\"algo\":\"CONV_ALGO_GEMM\",\n",out);
  fputs("\t\t\"layer_data\":[",out);
}

void typein_reorg(FILE * out, int s){
  if(first_layer==true)  fputs(",\n\t\t\t{",out);
  else {fputs("/n\t\t\t{",out);first_layer=true;}
  fputs("\n\t\t\t\"type\":\"reorg\",\n",out);
  fputs("\t\t\t\"weight_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"weight_offset\":0,\n",out);
  fputs("\t\t\t\"weight_size\":0,\n",out);
  fputs("\t\t\t\"bias_data\":\"NULL\",\n",out);
  fputs("\t\t\t\"bias_offset\":0,\n",out);
  fputs("\t\t\t\"bias_size\":0,\n",out);
  fputs("\t\t\t\"data\":{\n",out);
  fputs("\t\t\t\t\"stride\":",out);
  char a[20];
  sprintf(a,"%d\n",s);
  fputs(a,out);
  fputs("\t\t\t\t}\n\t\t\t}",out);
}

bool parse_yolocfg(const char* filename)
{
  FILE *fp = fopen(filename,"r");
  FILE *out = fopen("YOLO_sizes.json","wt+");
   if (fp == NULL || out == NULL){
    printf("Fail to open the file.\n");
    return false;
  }
  //estalish the net
  char msg[128];
  int init_input_w, init_input_h, init_input_d;
  //int last_output_w, last_output_h, last_output_d;
  std::vector<int> last_output_w, last_output_h, last_output_d;
  int index = 0;
  int num_layers = 0;
  while(fgets(msg,128,fp)){
    if (msg[0]=='[') num_layers++;
  }
  fseek(fp,0,SEEK_SET);
  head_typein(out, num_layers-1);
  while(fgets(msg,128,fp)!=NULL){
    //if (msg[0]=='[') printf("%s",msg);
    if (strcmp(msg, "[net]\n")==0){  //net
      while (fgets(msg,128,fp)){
        if (strlen(msg)==1) break;
        /*process net data */
        if (msg[0]=='#') continue;
        std::string temp(msg);
        boost::regex input_width("(width\\s*=\\s*)(\\d{1,})\n");
        boost::regex input_height("(height\\s*=\\s*)(\\d{1,})\n");
        boost::regex channels("(channels\\s*=\\s*)(\\d{1,})\n");
        boost::smatch result;
        if(boost::regex_match(temp,result,input_width)){
          init_input_w = atoi(result[2].str().c_str());
          last_output_w.push_back(init_input_w);
          //last_output_w = init_input_w;
        }
        if(boost::regex_match(temp,result,input_height)){
          init_input_h = atoi(result[2].str().c_str());
          last_output_h.push_back(init_input_h);
          //last_output_h = init_input_h;
        }
        if(boost::regex_match(temp,result,channels)){
          init_input_d = atoi(result[2].str().c_str());
          last_output_d.push_back(init_input_d);
          //last_output_d = init_input_d;
        }
      }
    }
    else if (strcmp(msg, "[convolutional]\n")==0){ // convolution
      index++;
      int i_b=1, \
          k_w, k_h, k_d, \
          k_s_w, k_s_h, k_p_w, k_p_h, \
          temp_out;
      boost::regex k_size("(size\\s*=\\s*)(\\d{1,})\n");
      boost::regex k_dep("(filters\\s*=\\s*)(\\d{1,})\n");
      boost::regex k_strike("(stride\\s*=\\s*)(\\d{1,})\n");
      boost::regex pad("(pad\\s*=\\s*)(\\d{1,})\n"); 
      boost::regex filters("(filters\\s*=\\s*)(\\d{1,})\n");
      while (fgets(msg,128,fp)){
        if (strlen(msg)==1) break;
        if (msg[0]=='#') continue;
        /*process conv data */
        //"input_width":224,"input_height":224,"input_depth":3,"input_batch":1,
        //"kernel_width":7,"kernel_height":7,"kernel_depth":64,
        //"kernel_stride_w":2,"kernel_stride_h":2,"k_padding_w":3,"k_padding_h":3
        std::string temp(msg);
        boost::smatch result;
        if(boost::regex_match(temp,result,k_size)){
          k_w = atoi(result[2].str().c_str());
          k_h = atoi(result[2].str().c_str());
        }
        if(boost::regex_match(temp,result,k_dep)){
          k_d = atoi((std::string(result[2].first,result[2].second)).c_str());
        }
        if(boost::regex_match(temp,result,k_strike)){
          k_s_w = atoi(result[2].str().c_str());
          k_s_h = k_s_w;
        }
        if(boost::regex_match(temp,result,pad)){
          k_p_w = atoi(result[2].str().c_str());
          k_p_h = k_p_w;
        }
        if(boost::regex_match(temp,result,filters)){
          temp_out = atoi(result[2].str().c_str());
        }
      }
      typein_conv(out,last_output_w[index-1], last_output_h[index-1], last_output_d[index-1], i_b, k_w, k_h, k_d, k_s_w, k_s_h, k_p_w, k_p_h);
      
      /*update the last_output*/
      //last_output_w.push_back((last_output_w[index-1] + k_p_w + k_p_h - k_w) / k_s_w + 1);
      //last_output_h.push_back((last_output_h[index-1] + k_p_h + k_p_h - k_h) / k_s_h + 1);
      //last_output_d.push_back(temp_out);
      last_output_w.push_back(last_output_w[index-1]);
      last_output_h.push_back(last_output_h[index-1]);
      last_output_d.push_back(last_output_d[index-1]);
    }
    else if (strcmp(msg, "[maxpool]\n")==0){  //maxpool
      index++;
      int i_b=1, \
          k_w, k_h, \
          k_s_w, k_s_h, \
          k_p_w=0, k_p_h=0, \
          p_type=1;
      //"input_width", "input_height", "input_depth"
      //"input_batch"
      //"kernel_width", "kernel_height" 
      //"kernel_stride_w", "kernel_stride_h" 
      //"k_padding_w", "k_padding_h", "pool_type"
      boost::regex k_size("(size\\s*=\\s*)(\\d{1,})\n");
      boost::regex k_stride("(stride\\s*=\\s*)(\\d{1,})\n");
      boost::smatch result; 
      while (fgets(msg,128,fp)){
        if (strlen(msg)==1) break;
        if (msg[0]=='#') continue;
        /*process maxpool data */
        std::string tmp(msg);
        if(boost::regex_match(tmp,result,k_size)){
          k_w = atoi(result[2].str().c_str());
          k_h = k_w;
        }
        if(boost::regex_match(tmp,result,k_stride)){
          k_s_w = atoi(result[2].str().c_str());
          k_s_h = k_s_w;
        }
      }
      typein_pool(out,last_output_w[index-1], last_output_h[index-1], last_output_d[index-1],\
                  i_b, \
                  k_w, k_h, \
                  k_s_w, k_s_h, \
                  k_p_w, k_p_h, \
                  p_type);
      last_output_w.push_back((last_output_w[index-1]-k_w)/k_s_w+1);
      last_output_h.push_back((last_output_h[index-1]-k_h)/k_s_h+1);
      last_output_d.push_back(last_output_d[index-1]);
    }
    else if (strcmp(msg, "[route]\n")==0){  //route
      //"input_width", "input_height", "input_depth", "output_width"
      index++;
      //int output_width=222;
      std::vector<int> index_prelayer;
      boost::regex layers("(layers\\s*=\\s*)(-?\\d{1,})[,(-?\\d{1,})]*\n");
      boost::smatch result;
      while (fgets(msg,128,fp)){
        if (strlen(msg)==1) break;
        if (msg[0]=='#') continue;
        /*process route data */
        std::string tmp(msg);
        if(boost::regex_match(tmp,result,layers)){
          int num_layers = result.size()-2;
          for(int i=0; i < num_layers; i++){
          index_prelayer.push_back(index + atoi(result[i+2].str().c_str()));
          }
        }
      }
      int out_d=0;
      for (int i=0; i < index_prelayer.size(); i++){
        out_d += last_output_d[index_prelayer[i]];
      }
     
      typein_route(out, last_output_w[index_prelayer[0]], last_output_h[index_prelayer[0]], out_d);
      last_output_w.push_back(last_output_w[index_prelayer[0]]);
      last_output_h.push_back(last_output_h[index_prelayer[0]]);
      last_output_d.push_back(out_d);
    }
    else if (strcmp(msg, "[region]\n")==0){   //region
      index++;
      int batch=1, \
          classes,coords,num,softmax;
      boost::regex re_classes("(classes\\s*=\\s*)(\\d{1,})\n");
      boost::regex re_coords("(coords\\s*=\\s*)(\\d{1,})\n");
      boost::regex re_num("(num\\s*=\\s*)(\\d{1,})\n");
      boost::regex re_softmax("(softmax\\s*=\\s*)(\\d{1,})\n");
      boost::smatch result;
      while (fgets(msg,128,fp)){
        if (strlen(msg)==1) break;
        if (msg[0]=='#') continue;
        /*process region data */
        std::string tmp(msg);
        if(boost::regex_match(tmp,result,re_classes)){
          classes = atoi(result[2].str().c_str());
        }
        if(boost::regex_match(tmp,result,re_coords)){
          coords = atoi(result[2].str().c_str());
        }
        if(boost::regex_match(tmp,result,re_num)){
          num = atoi(result[2].str().c_str());
        }
        if(boost::regex_match(tmp,result,re_softmax)){
          softmax = atoi(result[2].str().c_str());
        }
      }
      typein_region(out,last_output_w[index-1],last_output_h[index-1],last_output_d[index-1], \
                    batch, \
                    classes,coords,num,softmax);
    }
    else if (strcmp(msg, "[reorg]\n")==0){   //reorg
      int _stride;
      index++;
      boost::regex stride("(stride\\s*=\\s*)(\\d{1,})\n");
      boost::smatch result;
      while (fgets(msg,128,fp)){
        if (strlen(msg)==1) break;
        if (msg[0]=='#') continue;
        /*process region data */
        std::string tmp(msg);
        if(boost::regex_match(tmp,result,stride)){
          _stride = atoi(result[2].str().c_str());
        }
      }
      typein_reorg(out, _stride);
      last_output_w.push_back(last_output_w[index-1]/_stride);
      last_output_h.push_back(last_output_h[index-1]/_stride);
      last_output_d.push_back(last_output_d[index-1]/_stride/_stride);
    }
  }
  fputs("\n\t\t]\n\t}\n]",out);
  fclose(fp);
  fclose(out);
  std::cout << "Done.";
  return true;
}

int main(){
  parse_yolocfg("yolo.cfg");
  std::cin.get();
  return 0;
}