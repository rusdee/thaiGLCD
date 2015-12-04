
// ****** UTF8-Decoder: convert UTF8-string to Thai in extended ASCII *******

static byte temp;  // Last character buffer

// Convert a single Character from UTF8 to Thai in Extended ASCII
// Return "0" if a byte has to be ignored

byte utf8thai(byte presByte) {

    if (presByte < 0x80)
        return presByte;

    byte prevByte = temp;
    temp = presByte;
    
    if(prevByte == 0xB8)
        return presByte + 0x20;
        
    if(prevByte == 0xB9)
        return presByte + 0x60;

    return 0;

}


// convert String object from UTF8 String to Thai in Extended ASCII

String utf8thai(String inPut){	
    
    char c;
    String outPut = "";
    int i = 0, len = inPut.length();
    
    while(i < len)
      if (c = utf8thai(inPut.charAt(i++)))
        outPut += c;
    
    return outPut;
}


// In Place conversion UTF8-string to Thai in Extended ASCII (ASCII is shorter!)

void utf8thai(char* cPtr){

	char c;
	int i = 0, j = 0, len = strlen(cPtr);
  
	while(i < len)
		if (c = utf8thai(cPtr[i++]))
			cPtr[j++] = c;

	cPtr[j] = 0;
	
}
