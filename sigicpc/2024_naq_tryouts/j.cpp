#include <bits/stdc++.h>
using namespace std;

int main() {

	int l;
	long long x_num, x_denom, y_num, y_denom, z_num, z_denom;
	cin >> l >> x_num >> x_denom >> y_num >> y_denom >> z_num >> z_denom;

	vector<int> ternary_x;
	vector<int> ternary_y;
	vector<int> ternary_z;

	// convert x into ternary...
	// need l digits of precision
	long long digit_denom = 1;	
	for (int i = 0; i <= l; i++) {
		digit_denom *= 3;
		long long combined_num = x_num * digit_denom;
		long long digit_num = x_denom;

		long long digit = combined_num / digit_num;
		ternary_x.push_back(digit);

		if (digit != 0) {
			x_num = combined_num % digit_num;
			digit_denom = 1;
		}
	}

	// do the same for y...
	digit_denom = 1;	
	for (int i = 0; i <= l; i++) {
		digit_denom *= 3;
		long long combined_num = y_num * digit_denom;
		long long digit_num = y_denom;

		long long digit = combined_num / digit_num;
		ternary_y.push_back(digit);

		if (digit != 0) {
			y_num = combined_num % digit_num;
			digit_denom = 1;
		}
	}

	// and z...
	digit_denom = 1;	
	for (int i = 0; i <= l; i++) {
		digit_denom *= 3;
		long long combined_num = z_num * digit_denom;
		long long digit_num = z_denom;

		long long digit = combined_num / digit_num;
		ternary_z.push_back(digit);

		if (digit != 0) {
			z_num = combined_num % digit_num;
			digit_denom = 1;
		}
	}

	// keep track of whether points are exactly on the edge
	bool has_val_to_right_x[l + 1];
	bool has_val_to_right_y[l + 1];
	bool has_val_to_right_z[l + 1];
	memset(has_val_to_right_x, false, sizeof(has_val_to_right_x));
	memset(has_val_to_right_y, false, sizeof(has_val_to_right_y));
	memset(has_val_to_right_z, false, sizeof(has_val_to_right_z));

	bool found = false;
	for (int i = l - 1; i >= 0; i--) {
		if (found || ternary_x[i + 1] != 0) {
			found = true;
			has_val_to_right_x[i] = true;
		}
	}
	
	found = false;
	for (int i = l - 1; i >= 0; i--) {
		if (found || ternary_y[i + 1] != 0) {
			found = true;
			has_val_to_right_y[i] = true;
		}
	}

	found = false;
	for (int i = l - 1; i >= 0; i--) {
		if (found || ternary_z[i + 1] != 0) {
			found = true;
			has_val_to_right_z[i] = true;
		}
	}

	// now check for l layers of cube, are points in bounds
	for (int i = 0; i < l; i++) {
		int coords_in_void = 0;
		if (ternary_x[i] == 1 && has_val_to_right_x[i]) {
			coords_in_void++;
		}
		if (ternary_y[i] == 1 && has_val_to_right_y[i]) {
			coords_in_void++;
		}
		if (ternary_z[i] == 1 && has_val_to_right_z[i]) {
			coords_in_void++;
		}

		if (coords_in_void >= 2) {
			cout << 0 << endl;
			return 0;
		}
	}

	cout << 1 << endl;
}
