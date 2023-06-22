if(idx == -1){
        printf("-1");
        return 0;
    }
    for(int i = 0 ; i < n ;i++){
        if(arr[i] == temp[idx]){
            idx = i;
        }
    }

    printf("%d", idx);