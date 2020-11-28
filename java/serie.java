class Serie{
	public static void main(String[] args) {
		int j = 1;
		for (int i=1; i<=1000; i++ ) {
			if (j==1) {
				System.out.print(i + " ");
				j++;	
			} else if (j==2) {
				System.out.print(i + 1 + " ");
				j++;	
			} else if (j==3 ) {
				System.out.print(i + 2 + " ");
				j++;
			} else if (j==4) {
				System.out.print(i - 2 + " ");
				j++;
			} else if (j==5) {
				System.out.print(i - 1 + " ");
				j++;
			} else if (j==6) {
				System.out.print(i + " ");
				j=1;
			}
			

		}
	}
}