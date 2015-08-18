package com.cloud_sys.entity;

public class User {
	private String name;
	private String password;
	private String phone;
	private String email;

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "用户名: " + name + " 密码: " + password  + " 电话: " + phone + "邮箱" + email;
	}
}
