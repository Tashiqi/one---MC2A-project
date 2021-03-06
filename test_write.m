load data.mat;

file = fopen("data.in","w");

%Format for one row
format = [repmat('%f ',1,N-1),'%f\n'];

%Dimensions
fprintf(file,"%d %d\n",[M N]);

%Points
fprintf(file,format,X.');

%Labels
fprintf(file,"%d\n",y);

%Dimension test
fprintf(file,"%d\n",M_test);

%Test
fprintf(file,format,X_test.');


fclose(file);