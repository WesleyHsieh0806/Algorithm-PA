#說明: 每個.cpp 要先經過編譯變成 .o(object)檔案 再把不同.o變成執行檔executable binary
#格式請參考recitation的ptt

#variables

obj=main.o
exe=mps

#target part
#擺在最上面的target會被當作終極目標 完成這個目標就是make要做的事
$(exe): $(obj)
	g++ -O3 -o $@ $<
main.o: src/main.cpp
	g++ -c -O3 -o $@ $<




clean:
	rm -rf *.o mps *.outputs
