public class Movie {
    private String title;
    private String mipaa;
    private int numof1s = 0;
    private int numof2s = 0;
    private int numof3s = 0;
    private int numof4s = 0;
    private int numof5s = 0;

    public Movie(String t, String r){
        this.title = t;
        this.mipaa = r;
    }
    public void addRating(int num){
        if(num<1){
            System.out.println("This number is too low, only number from 1-5 accepted");
        } else if(num == 1){
            numof1s++;
        } else if(num == 2){
            numof2s++;
        } else if(num == 3){
            numof3s++;
        } else if(num == 4){
            numof4s++;
        } else if(num == 5){
            numof5s++;
        } else if(num > 5){
            System.out.println("Ok there bucko, there's no way the movie was THAT good. Only number from 1-5 accepted");
        }
    }
    public float getAverage(){
        int sum = numof1s
                + numof2s
                + numof3s
                + numof4s
                +numof5s;

        float average = (float)(1 * numof1s + 2 * numof2s + 3 * numof3s + 4 * numof4s + 5 * numof5s)/sum;
        return average;
    }
}
