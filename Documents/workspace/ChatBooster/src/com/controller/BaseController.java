package com.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class BaseController {
	
	protected String password = "Walk'n'shine@1988";

	public void clearSession(HttpServletRequest request,
			HttpServletResponse response) {
		request.getSession().invalidate();
		request.getSession(false);
	}

}
