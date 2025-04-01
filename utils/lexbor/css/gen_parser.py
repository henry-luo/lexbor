from gen_property import gen_property_c 
from gen_property_header import gen_property_h 
from gen_state_extra import gen_state_c 
from gen_state_extra_header import gen_state_h 

def gen_parser():
    gen_property_c()
    gen_property_h()
    gen_state_c()
    gen_state_h()
    print("Generated CSS property parser and header files successfully.")
    
if __name__ == "__main__":
    gen_parser()