package com.service;

import java.util.ArrayList;
import java.util.List;

import com.dao.FeedDao;
import com.domain.CategoryDomain;
import com.domain.EmailDomain;
import com.domain.FeedDomain;
import com.domain.UserDomain;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		Main main = new Main();
		main.addFeed();
	}

	public void deleteFeeds() {
		FeedDao dao = new FeedDao();
		FeedDomain feedDomain = dao.getFeedsById(10);

		List<FeedDomain> domains = new ArrayList<FeedDomain>();
		domains.add(feedDomain);

		dao.deleteFeeds(domains);

	}

	public void addandgetmails() {
		EmailDomain domain = new EmailDomain();
		domain.setEmailId("my rmia id");

		CategoryDomain categoryDomain = new CategoryDomain();
		categoryDomain.setCategoryId(1);
		List<CategoryDomain> categoryDomains = new ArrayList<CategoryDomain>();
		categoryDomains.add(categoryDomain);

		domain.setCategoryDomainList(categoryDomains);
		EmailService emailService = new EmailService();

		List<EmailDomain> domains = new ArrayList<EmailDomain>();
		domains.add(domain);
		try {
			emailService.addEmails(domains);
			domains = emailService.getEmailByCategories(categoryDomains);
			System.out.println(domains.size());
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public void addFeed() {

		FeedDomain feedDomain = new FeedDomain();
		feedDomain.setFeed("feed1234fewfwefref5");
		CategoryDomain categoryDomain = new CategoryDomain();
		categoryDomain.setCategoryId(1);
		List<CategoryDomain> categoryDomains = new ArrayList<CategoryDomain>();
		categoryDomains.add(categoryDomain);
		feedDomain.getCategoryDomainList().add(categoryDomain);
		List<FeedDomain> feedDomainList = new ArrayList<FeedDomain>();
		feedDomainList.add(feedDomain);

		FeedService feedService = new FeedService();
		try {
			feedService.addFeeds(feedDomainList);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void selectFeeds() {
		CategoryDomain categoryDomain = new CategoryDomain();
		categoryDomain.setCategoryId(1);
		List<CategoryDomain> categoryDomains = new ArrayList<CategoryDomain>();
		categoryDomains.add(categoryDomain);

		FeedDao dao = new FeedDao();
		List<FeedDomain> domains = dao.getFeedsByCategories(categoryDomains);
		for (FeedDomain domain : domains) {
			System.out.println(domain.getFeed());
		}
		System.out.println(domains.size());

	}

}
